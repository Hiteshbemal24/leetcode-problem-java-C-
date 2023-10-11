/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        Map<Integer, List<Node>> map = new HashMap<>();
        goDFS(0, root, map);
        for (int key : map.keySet()) {
            List<Node> list = map.get(key);
            for (int i = 1; i < list.size(); i++) {
                list.get(i - 1).next = list.get(i);
            }
        }
        return root;
    }

    private void goDFS(int lvl, Node root, Map<Integer, List<Node>> map) {
        if (root == null) return;

        List<Node> list = map.computeIfAbsent(lvl, k -> new ArrayList<>());
        list.add(root);
        lvl++;
        goDFS(lvl, root.left, map);
        goDFS(lvl, root.right, map);
    }
}
