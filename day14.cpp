// In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

// Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

// Return the sentence after the replacement.

 

// Example 1:

// Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"

class Solution {
public:
    class Node{
        public:
        Node* links[26];
        bool isterminal=false;
        bool size=false;

        void put(char ch)
        {
            if(links[ch-'a']==NULL)
            links[ch-'a']=new Node();

            return ;
        }
        bool contains(char ch)
        {
            if(links[ch-'a']!=NULL)
            {
                return true;
            }
            return false;
        }
        Node* getch(char ch)
        {
            return links[ch-'a'];
        }
        void setend()
        {
            isterminal=true;
        }
        void setsize()
        {
            size=true;
        }
      
        
    };
    public:
    class Trie{
        public:
        Node* node;
        Trie()
        {
            node=new Node();
        }
        void insert(string s)
        {
            Node* root=node;
            for(int i=0;i<s.length();i++)
            {
                if(root->contains(s[i]))
                {
                    root=root->getch(s[i]);
                }
                else{
                    root->put(s[i]);
                    root=root->getch(s[i]);
                }
            }
            root->isterminal=true;
            
        }
        string search(string s)
        {
             Node* root=node;
             string a="";
            for(int i=0;i<s.length();i++)
            {
                
               
                if(root->isterminal)
                {
                    return a;
                }
                else if(root->contains(s[i]))
                {
                    a+=s[i];
                    root=root->getch(s[i]);
                }
                else{
                    return "";
                }
                
            }
            cout<<a<<endl;
            if(root->isterminal==false)
            {
                return "";
            }
            return a;
        }
    };
    string replaceWords(vector<string>& d, string s) {
        Trie* node=new Trie();
        for(int i=0;i<d.size();i++)
        {
           node->insert(d[i]);
        }
        vector<string>v;
        string a="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                v.push_back(a);
                a="";
            }
            else{
                a+=s[i];
            }
        }
        v.push_back(a);
        
        string ans="";
        for(int i=0;i<v.size();i++)
        {
            string g=node->search(v[i]);
            
            if(g!="")
            {
                ans+=g;
              
                if(i!=v.size()-1)
                {
                    ans+=" ";
                }
            }
            else{
                ans+=v[i];
                if(i!=v.size()-1)
                {
                    ans+=" ";
                }
            }
        }
        return ans;
    }
};