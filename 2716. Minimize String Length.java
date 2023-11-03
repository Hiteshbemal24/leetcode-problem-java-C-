boolean map[] = new boolean[26];
        int ans = 0;
        for(char c : s.toCharArray()) 
            map[c - 'a'] = true;
        for(boolean b : map)
            if(b == true) ans ++;
        return ans;
