import java.util.*;
import java.io.*;
import java.lang.*;

public class monkeySigns {
   public static final String letters = "QWERTYUIOPASDFGHJKLZXCVBNM";
   public static void main(String[] args) throws Exception {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
      
      String s = br.readLine();
      s = s.toUpperCase();
      
      HashMap<String, Integer> map = new HashMap<String, Integer>();
      for (int i = 0; i < s.length(); ++i) {
         if (!letters.contains(s.substring(i, i+1))) {
            continue;
         }
         if (!map.containsKey(s.substring(i, i+1))) {
            map.put(s.substring(i, i+1), 1);
         } else {
            map.put(s.substring(i, i+1), map.get(s.substring(i, i+1)) + 1);
         }
      }
      
      int ans = 0;
      if (map.containsKey("M")) {
         ans = map.get("M");
      }
      int m = 0;
      for (String r : map.keySet()) {
         if (!r.equals("M")) {
            m = Math.max(m, map.get(r));
         }
      }
      
      pw.println(ans + m);
      pw.close();
   }
}