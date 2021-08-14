//TC: O(m*n) where m and n are number of elements in the two trees respectively.

bool isIdentical(Node *T, Node *S)
{
    if (T == NULL && S == NULL)
        return true;
    if (T == NULL || S == NULL)
        return false;
    if (T->data == S->data)
        return true;
    return (T->data == S->data) && isIdentical(T->left, S->left) && isIdentical(T->right, S->right);
}

bool isSubTree(Node *T, Node *S)
{
    if (!T)
        return false;
    if (!S)
        return true;
    if (isIdentical(T, S))
        return true;
    return isSubtree(T->left, S) || isSubTree(T->right, S);
}
