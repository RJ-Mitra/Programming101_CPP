//Trie implementation in cpp

//node is a pointer to a char node,
//children is a map with a char and the pointer to that char,
//isLeaf is a bool variable to mark if the last node is the end of word


#include<bits/stdc++.h>
using namespace std;


class TrieNode{
	public:
		unordered_map<char,TrieNode*> children;
		bool isLeaf;
};

TrieNode* getNewNode(){
	TrieNode* node = new TrieNode;
	node->isLeaf = false;
	return node;
}

void insert(TrieNode *&head, string word){//passing a reference to a pointer
	if(head == nullptr){//If the head node does not exist, we create a new head node
		head = getNewNode();
	}
	TrieNode *curr = head; //Setting head node to a pointer curr
	for(char c:word){//For each char in the word
		if(curr->children.find(c)==curr->children.end()){//If the char is not in the children map of the current node
			curr->children[c] = getNewNode();//creates a new node and assigns the pointer to that node to the new char in the children map
		}
		curr=curr->children[c];//Sets the curr pointer as the pointer to the node of the char
	}
	curr->isLeaf = true;//After all chars are inserted, the last char of the word is marked as leaf to signify end of word
}

bool hasChildren(TrieNode const *head){ //Passing a pointer
	for(auto i:head->children){//iterating over the children map of the node
		if(i.second != nullptr) return true;//if any valid (not null) pointer is present in the map, it has valid children
	}
	return false;//Return false if it has no valid children pointers
}

bool search(TrieNode *head, string word){//passing head node pointer
	if(head == nullptr) return false;//if the head is null, the word is not present in the trie
	TrieNode *curr = head;//Setting head pointer to the curr pointer
	for(char c:word){//iterating over each char in the word
		curr=curr->children[c];
		if(curr==nullptr) return false;
	}
	return curr->isLeaf;//If the last char is a leaf node (end of the word), the word is present in the trie
}

bool deletion(TrieNode *&curr, const string word, int depth = 0){//For deletion, we have to delete bottom upwards. Only if all children are deleted or has no dependencies for other words can we delete a head node
	if(curr==nullptr) return false; //If curr has no pointer reference, return
	if(depth < word.length()){ //Check for recursion to continue till last character
		if(curr!=nullptr && (curr->children.find(word.at(depth)) != curr->children.end()) //if curr is not null and if the char exists in the children map
		   && deletion(curr->children[word.at(depth)],word,depth+1) && curr->isLeaf==false){//and if all child elements of it are deleted and if it is not a leaf node
			if(!hasChildren(curr)){ //if it has no children, delete the node
				delete curr;
				curr = nullptr;
				return true;
			}else{ //else don't delete
				return false;
			}
		}
	}
	if(depth>=word.length() && curr->isLeaf==true){ //For the last node which is at the end of the word and is the leaf
		if(!hasChildren(curr)){ //if it has no children, delete the last node
			delete curr;
			curr = nullptr;
			return true;
		}else{ //if it has children/dependencies, deleting this node will delete other words as well
			curr->isLeaf=false; //set leaf to false instead of deleting, signifying it is not a complete word anymore and won't be returned in a search
			return true;
		}
	}
	return false;
}


//Driver

int main()
{
	TrieNode* head = nullptr;

	insert(head, "hello");
	cout << search(head, "hello") << " ";   	// print 1

	insert(head, "helloworld");
	cout << search(head, "helloworld") << " ";  // print 1

	cout << search(head, "helll") << " ";   	// print 0 (Not present)

	insert(head, "hell");
	cout << search(head, "hell") << " ";		// print 1

	insert(head, "h");
	cout << search(head, "h") << endl;  		// print 1 + newline

	deletion(head, "hello");
	cout << search(head, "hello") << " ";   	// print 0 (hello deleted)
	cout << search(head, "helloworld") << " ";  // print 1
	cout << search(head, "hell") << endl;   	// print 1 + newline

	deletion(head, "h");
	cout << search(head, "h") << " ";   		// print 0 (h deleted)
	cout << search(head, "hell") << " ";		// print 1
	cout << search(head, "helloworld") << endl; // print 1 + newline

	deletion(head, "helloworld");
	cout << search(head, "helloworld") << " ";  // print 0
	cout << search(head, "hell") << " ";		// print 1

	deletion(head, "hell");
	cout << search(head, "hell") << endl;   	// print 0 + newline

	if (head == nullptr)
		cout << "Trie empty!!\n";
	else
		cout<<"Not empty\n";			   		// Trie is empty now

	cout << search(head, "hell");   			// print 0

	return 0;
}
