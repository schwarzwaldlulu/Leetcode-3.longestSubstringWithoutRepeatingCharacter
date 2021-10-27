#include<set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0; //length of the longest substring w/o repeating character until now
        int l_substr = 0; // length of the current substring w/o repeating character
        string str = ""; // current substring w/o repeating char 
        set<char> chars; // save the chars in str
        
        for( int i = 0; i < s.length(); ++i )
        {
            if( chars.find( s[i] ) == chars.end() ) // current char not in the current str
            {
                str += s[i];
                l_substr++;
                chars.insert( s[i] );
            }
            else
            {
                l = max( l, l_substr );
                // update the str 
                int p = str.find( s[i] );
                string sub = str.substr( p+1 );
                str = sub + s[i];
                
                l_substr = str.length();
                chars.clear();
                for ( int j = 0; j < str.length(); ++j )
                    chars.insert( str[j] );
            }
        }
        return max( l, l_substr );
    }
};
