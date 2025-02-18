#include <iostream>

using namespace std;

class CSet
{
private:
struct Node
{
int iKey = 0;

Node* pLeft = nullptr; //smaller
Node* pRight = nullptr; //bigger
};

Node* m_pRoot = nullptr;
unsigned int m_uiSize = 0;

bool AddToNode(Node*& node, const int iKey);
bool AddExistedNode(Node*& node, Node*& nodeForAdd);
void DeleteNode(Node*& node, const int iKey);
bool CheckKey(const Node* node, const int iKey) const;
void PrintNode(const Node* node) const;
public:
CSet() {};
CSet(const CSet& obj) = delete;
~CSet() {};//!!!!

void Add(const int iKey);
void Delete(const int iKey);
bool IsExist(const int iKey) const;

void PrintTree() const;
void ClearAll();
void Clear(Node* node);
};

int main()
{
srand(time(NULL));

CSet st;

st.Add(24);
st.Add(12);
st.Add(45);
st.Add(100);

for (int i = 0; i < 5; ++i)
{
st.Add(rand() % 100);
}

st.PrintTree();
cout << "-----------\n\n";
st.Delete(24);
st.PrintTree();
cout << "-----------\n\n";
st.ClearAll();
st.PrintTree();

return 0;
}


void CSet::Add(const int iKey)
{
if (AddToNode(m_pRoot, iKey))
{
m_pRoot = new Node;
m_pRoot->iKey = iKey;
++m_uiSize;
}
}

bool CSet::AddToNode(Node*& node, const int iKey)
{
if (node == nullptr)
return true;

if (node->iKey > iKey)
{
if (AddToNode(node->pLeft, iKey))
{
Node* newNode = new Node;
newNode->iKey = iKey;

node->pLeft = newNode;
++m_uiSize;
}
}
else if (node->iKey < iKey)
{
if (AddToNode(node->pRight, iKey))
{
Node* newNode = new Node;
newNode->iKey = iKey;

node->pRight = newNode;
++m_uiSize;
}
}

return false;
}

bool CSet::AddExistedNode(Node*& node, Node*& nodeForAdd)
{
if (node == nullptr)
return true;

if (node->iKey > nodeForAdd->iKey)
{
if (AddExistedNode(node->pLeft, nodeForAdd))
node->pLeft = nodeForAdd;
}
else if (node->iKey < nodeForAdd->iKey)
{
if (AddExistedNode(node->pRight, nodeForAdd))
node->pRight = nodeForAdd;
}

return false;
}

void CSet::Delete(const int iKey)
{
DeleteNode(m_pRoot, iKey);
}

void CSet::DeleteNode(Node*& node, const int iKey)
{
if (node == nullptr)
return;

if (node->iKey == iKey)
{
Node* tmp = nullptr;

if (node->pRight != nullptr)
{
tmp = node->pRight;

if(node->pLeft != nullptr)
AddExistedNode(node->pRight, node->pLeft);
}
else if (node->pLeft != nullptr)
tmp = node->pLeft;

delete node;
node = tmp;

return;
}
else if (node->iKey > iKey)
DeleteNode(node->pLeft, iKey);
else
DeleteNode(node->pRight, iKey);

return;
}

bool CSet::IsExist(const int iKey) const
{
return CheckKey(m_pRoot, iKey);
}

bool CSet::CheckKey(const Node* node, const int iKey) const
{
if (node == nullptr)
return false;

if (node->iKey == iKey)
return true;
else if (node->iKey > iKey)
return CheckKey(node->pLeft, iKey);
else
return CheckKey(node->pRight, iKey);
}

void CSet::PrintTree() const
{
PrintNode(m_pRoot);
}

void CSet::PrintNode(const Node* node) const
{
if (node == nullptr)
return;

PrintNode(node->pLeft);
cout << node->iKey << "\n";
PrintNode(node->pRight);
}

void CSet::ClearAll()
{
    Clear(m_pRoot);
    m_pRoot = nullptr;
    m_uiSize = 0;
}

void CSet::Clear(Node* node)
{
    if(node == nullptr)
        return;

    Clear(node->pLeft);
    Clear(node->pRight);
    
    delete node;
}