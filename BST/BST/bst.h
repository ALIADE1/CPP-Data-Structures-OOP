#pragma once
#include <exception>
#include <stdexcept>
using namespace std;

template <class T>
struct TreeNode
{
	TreeNode(T v) : value(v), left(nullptr), right(nullptr) {}

	T value;
	TreeNode<T>* left;
	TreeNode<T>* right;
};

template <class T>
class BST
{
private:
	TreeNode<T>* root;

	void AddValueRecursive(TreeNode<T>* temp, T v)
	{
		if (!temp)
			return;
		else if (temp->value == v)
			throw runtime_error("Value already exists.");
		else if (temp->value > v)
		{
			if (!temp->left)
				temp->left = new TreeNode<T>(v);
			else
				AddValueRecursive(temp->left, v);
		}
		else
		{
			if (!temp->right)
				temp->right = new TreeNode<T>(v);
			else
				AddValueRecursive(temp->right, v);
		}
	}

	bool ExistRecursive(TreeNode<T>* temp, T v) {
		if (!temp)
			return false;
		else if (temp->value == v)
			return true;
		else if (temp->value > v)
			return ExistRecursive(temp->left, v);
		else
			return ExistRecursive(temp->right, v);
	}

	void DeleteTree(TreeNode<T>* node) {
		if (!node)
			return;
		DeleteTree(node->left);
		DeleteTree(node->right);
		delete node;
	}

public:
	BST() {
		root = nullptr;
	}

	~BST() {
		DeleteTree(root);
	}

	void AddValueRecursive(T v) {
		if (!root) {
			root = new TreeNode<T>(v);
		}
		else {
			AddValueRecursive(root, v);
		}
	}

	void AddValueIterative(T v) {
		if (!root) {
			root = new TreeNode<T>(v);
			return;
		}

		TreeNode<T>* current = root;
		while (current) {
			if (current->value == v) {
				throw runtime_error("Value already exists.");
			}
			else if (current->value < v) {
				if (!current->right) {
					current->right = new TreeNode<T>(v);
					return;
				}
				current = current->right;
			}
			else {
				if (!current->left) {
					current->left = new TreeNode<T>(v);
					return;
				}
				current = current->left;
			}
		}
	}

	bool ExistsRec(T v) {
		return ExistRecursive(root, v);
	}

	bool Exists(T v) {
		TreeNode<T>* temp = root;
		while (temp) {
			if (temp->value == v) {
				return true;
			}
			else if (temp->value > v) {
				temp = temp->left;
			}
			else {
				temp = temp->right;
			}
		}
		return false;
	}
};
