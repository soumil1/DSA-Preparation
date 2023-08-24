class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n)
        {
            int lineLength = words[i].size();
            int j = i + 1;

            // adding words until line exceeds max width
            while (j < n && lineLength + words[j].size() + (j - i - 1) < maxWidth)
            {
                lineLength += words[j].size();
                j++;
            }

            int numOfWords = j - i;
            int numOfSpaces = maxWidth - lineLength;

            // justified line constructed
            string line;

            // When there is only one word or it is the last line
            if (numOfWords == 1 || j == n)
            {
                line = words[i];
                for (int k = i + 1; k < j; k++)
                {
                    line += " " + words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            }
            else
            {
                int spacesBetween = numOfSpaces / (numOfWords - 1);
                int extraSpaces = numOfSpaces % (numOfWords - 1);

                line = words[i];
                for (int k = i + 1; k < j; k++)
                {
                    int spacesToAdd = spacesBetween + (extraSpaces > 0 ? 1 : 0);
                    line += string(spacesToAdd, ' ');
                    extraSpaces--;

                    line += words[k];
                }
            }
            ans.push_back(line);
            i = j; // Move to the next line of words
        }
        return ans;
    }
};
