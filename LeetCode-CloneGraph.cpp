#include "Debug.cpp"

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<int, Node*> map;
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node* newNode;
        if (map.count(node->val) == 0){
            newNode = new Node(node->val);
            map.insert({newNode->val,newNode});
            for (Node* neighbor : node->neighbors){
                newNode->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        else {
            newNode = map[node->val];
        }

        return newNode;
    }
};

int main(){
    Solution solution;
    Node* one = new Node(1);
    Node* two = new Node(2);
    Node* three = new Node(3);
    Node* four = new Node(4);

    one->neighbors.push_back(four);
    one->neighbors.push_back(two);

    two->neighbors.push_back(one);
    two->neighbors.push_back(three);
    
    three->neighbors.push_back(two);
    three->neighbors.push_back(four);
    
    four->neighbors.push_back(one);
    four->neighbors.push_back(three);

    solution.cloneGraph(one);

    delete one,two,three,four;

}