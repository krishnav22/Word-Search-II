struct TrieNode
{
   bool isWord;
   TrieNode* child[26];

};
class Solution {

void insert(TrieNode* root,string word)
{
    int n=word.size();
    for(int i=0;i<n;i++)
    {
        int idx=word[i]-'a';

        if(root->child[idx]==NULL)
        {
            root->child[idx]=new TrieNode();
        }
        root=root->child[idx];
    }
    root->isWord=true;
}

public:

    void check_word(vector<vector<char>>& board,int i,int j,int n,int m,TrieNode* root,vector<vector<bool>> &visited,vector<string> &ans,string s)
    {   
        if(root->isWord)
        {
            ans.push_back(s);
            root->isWord=false;
        }
        if(i<0 || j<0 || i>=n | j>=m) return;
        if(visited[i][j]) return;
        visited[i][j]=true;

         char cur=board[i][j];
         if(root->child[cur-'a'] !=NULL)
         {
            s.push_back(cur);          
            check_word(board,i+1,j,n,m,root->child[cur-'a'],visited,ans,s);
            check_word(board,i-1,j,n,m,root->child[cur-'a'],visited,ans,s);
            check_word(board,i,j-1,n,m,root->child[cur-'a'],visited,ans,s);
            check_word(board,i,j+1,n,m,root->child[cur-'a'],visited,ans,s);
            s.pop_back();
         }
         visited[i][j]=false;    
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        int n=board.size();
        int m=board[0].size();
        int wordn=words.size();
        if(wordn==0) return {};
    
        TrieNode* root= new TrieNode();
        for(int i=0;i<wordn;i++) 
        { 
            insert(root,words[i]);
        }
        
         vector<vector<bool>> visited(n,vector<bool>(m,false));
      
        vector<string> ans;
         for(int i=0;i<n;i++)
         {
              for(int j=0;j<m;j++)
              {
                  
                    char cur=board[i][j];
                    if(root->child[cur-'a'] !=NULL)
                    {
                        check_word(board,i,j,n,m,root,visited,ans,"");
                    }
              }
        }
         
        return ans;  
    }
};
