#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
#include <cmath>

using namespace std;

const int INF = numeric_limits<int>::max();

// 树节点结构，用于生成SVG
struct TreeNode {
    int id;
    int parentId;
    int level;
    int cost;
    int lowerBound;
    vector<int> assignment;
    bool isActive;
    bool isSolution;
    double x, y;
};

// 用于优先队列的节点
struct Node {
    vector<int> assignment; // 当前指派，-1表示未指派
    int cost;              // 当前成本
    int lowerBound;        // 下界
    int level;             // 当前处理的雇员索引
    int id;                // 节点ID
    int parentId;          // 父节点ID
    
    // 优先队列比较函数（最小堆）
    bool operator>(const Node& other) const {
        return lowerBound > other.lowerBound;
    }
};

class AssignmentProblem {
private:
    vector<vector<int>> costMatrix;
    int n;
    vector<TreeNode> treeNodes;
    int nodeCounter;
    
public:
    AssignmentProblem(const vector<vector<int>>& matrix) : costMatrix(matrix), n(matrix.size()), nodeCounter(0) {}
    
    // 计算下界函数
    int calculateLowerBound(const vector<int>& assignment, int level) {
        int bound = 0;
        
        // 计算已指派任务的成本
        for (int i = 0; i < level; i++) {
            if (assignment[i] != -1) {
                bound += costMatrix[i][assignment[i]];
            }
        }
        
        // 为未指派的雇员计算最小可能成本
        for (int i = level; i < n; i++) {
            int minCost = INF;
            for (int j = 0; j < n; j++) {
                // 检查工作j是否已被指派
                bool assigned = false;
                for (int k = 0; k < level; k++) {
                    if (assignment[k] == j) {
                        assigned = true;
                        break;
                    }
                }
                if (!assigned && costMatrix[i][j] < minCost) {
                    minCost = costMatrix[i][j];
                }
            }
            if (minCost != INF) {
                bound += minCost;
            }
        }
        
        return bound;
    }
    
    // 解决指派问题
    pair<int, vector<int>> solve() {
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        treeNodes.clear();
        nodeCounter = 0;
        
        // 根节点
        Node root;
        root.assignment = vector<int>(n, -1);
        root.level = 0;
        root.cost = 0;
        root.lowerBound = calculateLowerBound(root.assignment, 0);
        root.id = nodeCounter++;
        root.parentId = -1;
        
        // 添加根节点到树结构
        TreeNode rootTreeNode;
        rootTreeNode.id = root.id;
        rootTreeNode.parentId = root.parentId;
        rootTreeNode.level = root.level;
        rootTreeNode.cost = root.cost;
        rootTreeNode.lowerBound = root.lowerBound;
        rootTreeNode.assignment = root.assignment;
        rootTreeNode.isActive = true;
        rootTreeNode.isSolution = false;
        treeNodes.push_back(rootTreeNode);
        
        pq.push(root);
        
        int bestCost = INF;
        vector<int> bestAssignment;
        
        while (!pq.empty()) {
            Node current = pq.top();
            pq.pop();
            
            // 更新树节点状态
            for (auto& node : treeNodes) {
                if (node.id == current.id) {
                    node.isActive = false;
                    break;
                }
            }
            
            // 如果当前下界已经大于已知最优解，剪枝
            if (current.lowerBound >= bestCost) {
                continue;
            }
            
            // 如果是叶子节点，检查是否为更好解
            if (current.level == n) {
                if (current.cost < bestCost) {
                    bestCost = current.cost;
                    bestAssignment = current.assignment;
                    
                    // 标记为解节点
                    for (auto& node : treeNodes) {
                        if (node.id == current.id) {
                            node.isSolution = true;
                            break;
                        }
                    }
                }
                continue;
            }
            
            // 生成子节点
            for (int job = 0; job < n; job++) {
                // 检查工作是否已被指派
                bool assigned = false;
                for (int i = 0; i < current.level; i++) {
                    if (current.assignment[i] == job) {
                        assigned = true;
                        break;
                    }
                }
                
                if (!assigned) {
                    Node child = current;
                    child.assignment[child.level] = job;
                    child.cost += costMatrix[child.level][job];
                    child.level++;
                    child.lowerBound = calculateLowerBound(child.assignment, child.level);
                    child.parentId = current.id;
                    child.id = nodeCounter++;
                    
                    // 只有当下界小于当前最优解时才加入队列
                    if (child.lowerBound < bestCost) {
                        pq.push(child);
                        
                        // 添加到树结构
                        TreeNode childTreeNode;
                        childTreeNode.id = child.id;
                        childTreeNode.parentId = child.parentId;
                        childTreeNode.level = child.level;
                        childTreeNode.cost = child.cost;
                        childTreeNode.lowerBound = child.lowerBound;
                        childTreeNode.assignment = child.assignment;
                        childTreeNode.isActive = true;
                        childTreeNode.isSolution = false;
                        treeNodes.push_back(childTreeNode);
                    }
                }
            }
        }
        
        return {bestCost, bestAssignment};
    }
    
    // 生成SVG图像
    void generateSVG(const string& filename) {
        // 计算节点位置
        calculateNodePositions();
        
        ofstream svgFile(filename);
        
        // SVG头部
        svgFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
        svgFile << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"1200\" height=\"800\" viewBox=\"0 0 1200 800\">" << endl;
        
        // 背景
        svgFile << "<rect width=\"1200\" height=\"800\" fill=\"#f0f0f0\"/>" << endl;
        
        // 绘制连接线
        svgFile << "<g stroke=\"#666\" stroke-width=\"2\">" << endl;
        for (const auto& node : treeNodes) {
            if (node.parentId != -1) {
                auto parent = find_if(treeNodes.begin(), treeNodes.end(), 
                                    [&](const TreeNode& n) { return n.id == node.parentId; });
                if (parent != treeNodes.end()) {
                    svgFile << "<line x1=\"" << parent->x << "\" y1=\"" << parent->y + 30 
                           << "\" x2=\"" << node.x << "\" y2=\"" << node.y - 10 << "\"/>" << endl;
                }
            }
        }
        svgFile << "</g>" << endl;
        
        // 绘制节点
        for (const auto& node : treeNodes) {
            string color = "#ffffff";
            string stroke = "#333";
            
            if (node.isSolution) {
                color = "#90EE90"; // 解节点 - 浅绿色
                stroke = "#006400";
            } else if (!node.isActive) {
                color = "#d3d3d3"; // 已处理节点 - 浅灰色
            } else {
                color = "#87CEEB"; // 活动节点 - 浅蓝色
            }
            
            // 节点矩形
            svgFile << "<rect x=\"" << node.x - 40 << "\" y=\"" << node.y - 20 
                   << "\" width=\"80\" height=\"40\" rx=\"5\" fill=\"" << color 
                   << "\" stroke=\"" << stroke << "\" stroke-width=\"2\"/>" << endl;
            
            // 节点文本
            svgFile << "<text x=\"" << node.x << "\" y=\"" << node.y + 5 
                   << "\" text-anchor=\"middle\" font-family=\"Arial\" font-size=\"10\">";
            svgFile << "ID:" << node.id << " LB:" << node.lowerBound;
            svgFile << "</text>" << endl;
            
            // 指派信息
            string assignmentStr = "Asgn:";
            for (int i = 0; i < node.level; i++) {
                if (node.assignment[i] != -1) {
                    assignmentStr += to_string(node.assignment[i]);
                    if (i < node.level - 1) assignmentStr += ",";
                }
            }
            
            svgFile << "<text x=\"" << node.x << "\" y=\"" << node.y - 25 
                   << "\" text-anchor=\"middle\" font-family=\"Arial\" font-size=\"8\" fill=\"#333\">";
            svgFile << assignmentStr;
            svgFile << "</text>" << endl;
        }
        
        // 图例
        svgFile << "<g font-family=\"Arial\" font-size=\"12\">" << endl;
        svgFile << "<rect x=\"20\" y=\"20\" width=\"20\" height=\"20\" fill=\"#87CEEB\" stroke=\"#333\"/>" << endl;
        svgFile << "<text x=\"50\" y=\"35\">活动节点</text>" << endl;
        svgFile << "<rect x=\"20\" y=\"50\" width=\"20\" height=\"20\" fill=\"#d3d3d3\" stroke=\"#333\"/>" << endl;
        svgFile << "<text x=\"50\" y=\"65\">已处理节点</text>" << endl;
        svgFile << "<rect x=\"20\" y=\"80\" width=\"20\" height=\"20\" fill=\"#90EE90\" stroke=\"#006400\"/>" << endl;
        svgFile << "<text x=\"50\" y=\"95\">最优解</text>" << endl;
        svgFile << "</g>" << endl;
        
        svgFile << "</svg>" << endl;
        svgFile.close();
    }
    
private:
    void calculateNodePositions() {
        // 按层级组织节点
        vector<vector<TreeNode*>> levels(n + 1);
        for (auto& node : treeNodes) {
            if (node.level < levels.size()) {
                levels[node.level].push_back(&node);
            }
        }
        
        // 计算位置
        double levelHeight = 700.0 / (n + 2);
        for (int level = 0; level < levels.size(); level++) {
            int nodesInLevel = levels[level].size();
            double levelWidth = 1000.0 / (nodesInLevel + 1);
            
            for (int i = 0; i < nodesInLevel; i++) {
                TreeNode* node = levels[level][i];
                node->x = 100 + (i + 1) * levelWidth;
                node->y = 50 + level * levelHeight;
            }
        }
    }
};

int main() {
    // 给定的耗费矩阵
    vector<vector<int>> costMatrix = {
        {3, 5, 2, 4},
        {6, 7, 5, 3},
        {3, 7, 4, 5},
        {8, 5, 4, 6}
    };
    
    AssignmentProblem problem(costMatrix);
    
    cout << "求解指派问题..." << endl;
    cout << "耗费矩阵:" << endl;
    for (const auto& row : costMatrix) {
        for (int cost : row) {
            cout << cost << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    auto result = problem.solve();
    
    cout << "最优总耗费: " << result.first << endl;
    cout << "最优指派方案:" << endl;
    for (int i = 0; i < result.second.size(); i++) {
        cout << "雇员 " << i + 1 << " -> 工作 " << result.second[i] + 1 << endl;
    }
    
    // 生成SVG图像
    problem.generateSVG("assignment_tree.svg");
    cout << "\n状态空间树已保存到 assignment_tree.svg" << endl;
    
    return 0;
}