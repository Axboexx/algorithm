#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 哈夫曼树的节点
struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// 堆中节点的比较函数
struct Compare {
    bool operator()(Node *left, Node *right) {
        return left->freq > right->freq;
    }
};

// 通过堆排序构建哈夫曼树
Node *buildHuffmanTree(vector<char> &data, vector<int> &freq) {
    priority_queue<Node *, vector<Node *>, Compare> minHeap;

    // 创建叶子节点并加入最小堆中
    for (int i = 0; i < data.size(); ++i) {
        minHeap.push(new Node(data[i], freq[i]));
    }

    while (minHeap.size() != 1) {
        Node *left = minHeap.top();
        minHeap.pop();

        Node *right = minHeap.top();
        minHeap.pop();

        Node *newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    return minHeap.top();
}

// 打印哈夫曼编码
void printHuffmanCodes(Node *root, string code) {
    if (root == nullptr) {
        return;
    }

    if (root->data != '$') {
        cout << root->data << ": " << code << endl;
    }

    printHuffmanCodes(root->left, code + "0");
    printHuffmanCodes(root->right, code + "1");
}

int main() {
    vector<char> data = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    Node *root = buildHuffmanTree(data, freq);

    cout << "哈夫曼编码：" << endl;
    printHuffmanCodes(root, "");

    return 0;
}
