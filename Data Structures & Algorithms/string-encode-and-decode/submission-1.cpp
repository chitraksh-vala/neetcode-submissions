class Solution {
public:
    string encode(vector<string>& strs) {
        string code;

        // store lengths
        for (string s : strs) {
            code.push_back((char)s.size());
        }

        // special separator (>199 impossible length)
        code.push_back((char)255);

        // append strings
        for (string s : strs) {
            code += s;
        }

        return code;
    }

    vector<string> decode(string code) {
        vector<int> lengths;
        vector<string> result;

        int index = 0;

        // read lengths
        while ((unsigned char)code[index] != 255) {
            lengths.push_back((unsigned char)code[index]);
            index++;
        }

        index++; // move after separator

        // reconstruct strings
        for (int len : lengths) {
            result.push_back(code.substr(index, len));
            index += len;
        }

        return result;
    }
};