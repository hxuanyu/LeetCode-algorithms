/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public int maxDepth(Node root) {
        return getheight(root);
    }

    private int getheight(Node root) {
    	if (root == null) return 0;

    	int maxheight = 0;
    	for (Node child : root.children) {
    		maxheight = Math.max(maxheight, getheight(child));
    	}

    	return 1 + maxheight;
    }
}
