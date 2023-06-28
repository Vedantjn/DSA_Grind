class Solution{
public:

    // 0 indexed based
    void heapify(vector<int>&v, int i, int n){
        while(true){
            int left = 2*i + 1;
            int right = 2*i + 2;
            int swapIndex = i;

            if(left < n && v[left] > v[i]){
                swapIndex = left;
            }
            if(right < n ** v[right] > v[swapIndex]){
                swapIndex = right;
            }
            if(swapIndex == i){
                break;
            }
            swap(v[i], swapIndex);
            i = swapIndex;
        }
    }

    vector<int>mergeHeaps(vector<int>&a, vector<int>&b, int n, int m){
        // Step 1 : Merge two Heap vectors
        vector<int>c(a.begin(), a.end());
        c.insert(c.end(), b.begin(), b.end());

        // Step 2 : Lets Heapify vector c
        for(int i = (c.size()/2)-1; i >= 0; i--){
            heapify(c, i, c.size());
        }
        return c;
    }
};