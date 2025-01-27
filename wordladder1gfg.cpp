//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({startWord,1});
        st.erase(startWord);
        while(!q.empty()){
            string current = q.front().first;
            int steps = q.front().second;
            if(current == targetWord){
                return steps;
            }
            q.pop();
            for(int i =0;i<current.size();i++){
                string original = current;
                for(char ch = 'a';ch <= 'z';ch++){
                    current[i] = ch;
                    if(st.find(current)!=st.end()){
                        st.erase(current);
                        q.push({current,steps + 1});
                    }
                }
                current = original;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends