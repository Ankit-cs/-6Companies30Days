/*
May be the brute force wikk work till 30 inputs but then it will give answer 

### Intuition for the Code:

1. **Sorting Contacts**: The list of contacts is first sorted lexicographically to make it easier to search for matching prefixes. This ensures that when we search for matches for a given prefix, the matches are returned in lexicographical order.

2. **Prefix Construction**: The idea is to progressively build the prefix from the query string `s`. For each character in the query string, we form the prefix and check for contacts that start with this prefix.

3. **Matching Contacts**: For each prefix, we loop through all the contacts and check if the current contact starts with the current prefix using `substr(0, prefix.length())`. If a contact matches the prefix, it is added to the list of matches.

4. **Handling No Matches**: If no contact matches the current prefix, the result for that prefix is `{"0"}`, indicating no contacts found for that prefix.

5. **Result Construction**: The result for each prefix is stored in a 
*/
/*
optimal used by  a Trie data structure kuch samajh nahib aya kya hai yeh
Go th GFG editorials */

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    struct TrieNode{
    	unordered_map<char,TrieNode*> child;
    	bool isLast;
    	TrieNode(){
    		for (char i = 'a'; i <= 'z'; i++)
    			child[i] = NULL;
    		isLast = false;
    	}
    };
    TrieNode *root = NULL;

    void insert(string s){
    	int len = s.length();
    	TrieNode *itr = root;
    	for (int i = 0; i < len; i++){
    		TrieNode *nextNode = itr->child[s[i]];
    		if (nextNode == NULL){
    			nextNode = new TrieNode();
    			itr->child[s[i]] = nextNode;
    		}
    		itr = nextNode;
    		if (i == len - 1)
    			itr->isLast = true;
    	}
    }

    void insertIntoTrie(string s[],int n){
    	root = new TrieNode();
    	for (int i = 0; i < n; i++)
    		insert(s[i]);
    }

    void displayContactsUtil(TrieNode *curNode, string prefix, 
                            vector<string> &vec){
    	if (curNode->isLast)
    		    vec.push_back(prefix);
    	for (char i = 'a'; i <= 'z'; i++){
    		TrieNode *nextNode = curNode->child[i];
    		if (nextNode != NULL)
    			displayContactsUtil(nextNode, prefix + (char)i, vec);
    	}
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
    	insertIntoTrie(contact, n);
    	TrieNode *prevNode = root;
        vector<vector<string>> res;
    	string prefix = "";
    	int len = s.length();
    	int i;

    	for (i = 0; i < len; i++){
    		vector<string> v;
    		prefix += (char)s[i];
    		char lastChar = prefix[i];
    		TrieNode *curNode = prevNode->child[lastChar];
    		
    		if (curNode == NULL){
    			v.push_back("0");
    			res.push_back(v);
    			i++;
    			break;
    		}
    		displayContactsUtil(curNode, prefix, v);
    		prevNode = curNode;
    		res.push_back(v);
    	}
    	
    	for (; i<len; i++){
    	    vector<string> v;
    	    v.push_back("0");
    	    res.push_back(v);
    	}
    	
    	return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends