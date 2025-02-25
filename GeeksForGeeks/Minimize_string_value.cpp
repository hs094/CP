//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int minValue(string S, int K)
	{
	    // Your code goes here
	    priority_queue<int> pq;
	    map<char,int> mp;
	    for(int i=0;i<S.size();i++) {
	        mp[S[i]]++;
	    }
	    for(auto it: mp) pq.push(it.second);
	    while(!pq.empty() && K-- > 0) {
	        int t = pq.top();
	        pq.pop();
	        if(t-1 > 0) pq.push(t-1);
	    }
	    int sum = 0;
	    while(!pq.empty()) {
	        sum += pq.top()*pq.top();
	        pq.pop();
	    }
	    return sum;
	}
};

//{ Driver Code Starts.

int main() 
{
   
   
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		int k;
   		cin >> k;
        Solution ob;

   		cout << ob.minValue(s, k);

   		cout << "\n";
   	
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends