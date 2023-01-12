template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<int> *right;
    TreeNode<int> *left;
    TreeNode(T data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    }
};