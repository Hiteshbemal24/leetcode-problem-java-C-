class Solution {
    public int romanToInt(String s) {
     HashMap<Character, Integer> help = new HashMap<Character, Integer>();
        initHelp(help);
        int ans = 0;
        for (int i = 0; i < s.length(); i ++){
        if ( i > 0 && help.get(s.charAt(i)) > help.get(s.charAt(i-1))) {
                ans = ans - 2 * help.get(s.charAt(i-1));
            }
            ans = ans + help.get(s.charAt(i));
        }
        return ans;
    }
    private void initHelp(HashMap<Character, Integer> help) {
        help.put('M', 1000);
        help.put('D', 500);
        help.put('C', 100);
        help.put('L', 50);
        help.put('X', 10);
        help.put('V', 5);
        help.put('I', 1);

    }
}
