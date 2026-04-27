class Solution {
public:
    
    void computeLPS(string &pat, vector<int> &lps) {
        int m = pat.length();
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> search(string &pat, string &txt) {
        int n = txt.length();
        int m = pat.length();

        vector<int> lps(m);
        vector<int> result;

        computeLPS(pat, lps);

        int i = 0; 
        int j = 0;

        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            
            if (j == m) {
                result.push_back(i - j);
                j = lps[j - 1];
            }

         
            else if (i < n && txt[i] != pat[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }
};