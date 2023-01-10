#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T val)
    {
        data = val;
    }

    ~TreeNode()
    {
        for (int i = 0; children.size(); i++)
        {
            delete children[i];
        }
    }
};