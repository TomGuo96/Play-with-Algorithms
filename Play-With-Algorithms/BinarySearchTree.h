//
//  BinarySearchTree.h
//  Algorithm
//
//  Created by Tom Guo on 23/09/2017.
//  Copyright © 2017 Tom Guo. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <iostream>
#include <cassert>
#include <queue>

using namespace std;

/*
 * 思考题：
 * insert的非递归写法
 * successor和predecessor的实现
 * floor与ceil函数
 * rank与select函数
 * 支持重复元素的二分搜索树
 *
 * 平衡二叉树：
 * 红黑树、2-3 Tree、AVL Tree、Splay Tree
 *
 * 平衡二叉树和堆的结合：Treap
 *
 * Trie：查找效率与单词长度有关
 */

template <class Key, class Value>
class BinarySearchTree{
	
private:
	
	struct Node{
		
		Key key;
		Value value;
		Node* left;
		Node* right;
		
		Node(Key key, Value value){
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}
		
		Node(Node *node){
			this->key = node->key;
			this->value = node->value;
			this->left = node->left;
			this->right = node->right;
		}
		
	};
	
	Node *root;
	int count;
	
//	向以root为根的二叉搜索树中，插入节点(key, value)，返回插入新节点后的二叉搜索树
	Node* insert(Node *node, Key key, Value value){
		
		if(node == NULL){
			count++;
			return new Node(key, value);
		}
		
		if(key == node->key){
			node->value = value;
		} else if(key < node->key){
			node->lert = insert(node->left, key, value);
		} else {
			node->right = insert(node->right, key, value);
		}
		return node;
	}
	
	Node* contain(Node* node, Key key){
		
		if(node == NULL){
			return false;
		}
		if(key == node->key){
			return true;
		} else if(key < node->key){
			return contain(node-left, key);
		} else {
			return contain(node-right, key);
		}
	}
	
	Value* search(Node* node, Key key){
		
		if(node == NULL){
			return NULL;
		} else if(key == node->key){
			return &(node->value);
		} else if(key < node->key){
			return search(node->left, key);
		} else {
			return search(node->right, key);
		}
	}
	
	// 对以node为根的子树进行前序遍历
	void preOrder(Node* node){
		
		if(node != NULL){
			cout<<node->key<<endl;
			preOrder(node->left);
			preOrder(node->right);
		}
		
	}
	
	// 对以node为根的子树进行中序遍历
	void inOrder(Node* node){
		
		if(node != NULL){
			inOrder(node->left);
			cout<<node->key<<endl;
			inOrder(node->right);
		}
		
	}
	
	// 对以node为根的子树进行后序遍历
	void postOrder(Node* node){
		
		if(node != NULL){
			postOrder(node->left);
			postOrder(node->right);
			cout<<node->key<<endl;
		}
		
	}
	
	// 销毁以node为根的子树
	void destroy(Node* node){
		
		if(node != NULL){
			destroy(node->left);
			destroy(node->right);
			delete node;
			count--;
		}
	}
	
	// 在以node为根的子树中，返回最小值
	Node* minimum(Node* node){
		
		if(node->left == NULL){
			return node;
		}
		return minimum(node->left);
		
	}
	
	// 在以node为根的子树中，返回最大值
	Node* maximum(Node* node){
		
		if(node->right == NULL){
			return node;
		}
		return minimum(node->right);
		
	}
	
	// 删除以node为节点为根的最小节点，返回删除节点后的新的根
	Node* removeMin(Node* node){
		
		if(node->left == NULL){
			Node* rightNode = node->right;
			delete node;
			count--;
			return rightNode;
		}
		node->left = removeMin(node->left);
		return node;
	}
	
	// 删除以node为节点为根的最大节点，返回删除节点后的新的根
	Node* removeMax(Node* node){
		
		if(node->right == NULL){
			Node* leftNode = node->left;
			delete node;
			count--;
			return leftNode;
		}
		node->right = removeMax(node-right);
		return node;
	}
	
	/*
	 * 思考题：还可以使用左子树中的最大值来代替
	 */
	
	// Hubbard Deletion
	// 删除掉node为根的树中的值为key的节点，返回删除节点后新的树的根
	Node* remove(Node* node, Key key){
		if(node == NULL){
			return;
		}
		if(key < node->key){
			node->left = remove(node->left, key);
			return node;
		} else if(key > node->key){
			node->right = remove(node->right, key);
			return node;
		} else {
			// key = node->key
			if(node->left == NULL){
				Node* rightNode = node->right;
				delete node;
				count--;
				return rightNode;
			}
			if(node->right == NULL){
				Node* leftNode = node->left;
				delete node;
				count--;
				return leftNode;
			}
			// node->left != NULL && node->right != NULL
			// successor指向最小值，下一步删除了最小值，使得succussor指向失败，所以要复制一份最小值的节点
			Node* successor = new Node(minimum(node->right));
			count++;
			successor->right = removeMin(node->right);
			successor->left = node->left;
			delete node;
			count--;
			return successor;
		}
	}
	
public:
	
	BinarySearchTree(){
		root = NULL;
		count = 0;
	}
	~BinarySearchTree(){
		destroy(root);
	}
	
	int size(){
		return count;
	}
	bool isEmpty(){
		return count == 0;
	}
	void insert(Key key, Value value){
		root = insert(root, key, value);
	}
	bool contain(Key key){
		return contain(root, key);
	}
	Value* search(Key key){
		return search(root, key);
	}
	
	// 前序遍历
	void preOrder(){
		preOrder(root);
	}
	// 中序遍历
	void inOrder(){
		inOrder(root);
	}
	// 后序遍历
	void postOrder(){
		postOrder(root);
	}
	// 层序遍历
	void levelOrder(){
		
		queue<Node*> q;
		q.push(root);
		while(!q.empty()){
			
			Node *node = q.front();
			q.pop();
			cout<<node->key<<endl;
			if(node->left){
				q.push(node->left);
			}
			if(node->right){
				q.push(node->right);
			}
			
		}
	}
	
	// 寻找最小的键值
	Key minimum(){
		assert(count != 0);
		Node* minNode = minimum(root);
		return minNode->key;
	}
	
	// 寻找最大的键值
	Key maximum(){
		assert(count != 0);
		Node* maxNode = maximum(root);
		return maxNode->key;
	}
	
	// 删除最小值的所在节点
	void removeMin(){
		
		if(root){
			root = removeMin(root);
		}
		
	}
	
	// 删除最大值的所在节点
	void removeMax(){
		
		if(root){
			root = removeMax(root);
		}
		
	}
	
	// 从二叉树中删除键值为key的节点
	void remove(Key key){
		root = remove(root, key);
	}
};

#endif /* BinarySearchTree_h */
