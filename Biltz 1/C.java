import java.util.*;
import java.io.*;
import java.lang.*;

// yay it worked first try
public class C {
    public static int[][] a;
    public static int n, k;
    public static boolean[][] visited;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        a = new int[n][n];
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; ++j) a[i][j] = Integer.parseInt(st.nextToken());
        }

        int low = 0;
        int high = (int)(1e9);
        int ans = 0;
        while (low != high) {
            int mid = (low+high)/2;
            if (isValid(mid)) {
                high = mid;
                ans = mid;
            }
            else low = mid + 1;
        }
        pw.println(ans);
        pw.close();
    }
    public static boolean isValid(int tmp) {
        visited = new boolean[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j]) {
                    int currSize = floodfill(i, j, tmp);
                    if (currSize >= k) return true;
                }
            }
        }
        return false;
    }
    public static int floodfill(int r, int c, int tmp) {
        if (visited[r][c]) return 0;
        visited[r][c] = true;
        int res = 1;
        if (r > 0 && Math.abs(a[r][c]-a[r-1][c]) <= tmp) res += floodfill(r-1, c, tmp);
        if (c > 0 && Math.abs(a[r][c]-a[r][c-1]) <= tmp) res += floodfill(r, c-1, tmp);
        if (r < n-1 && Math.abs(a[r][c]-a[r+1][c]) <= tmp) res += floodfill(r+1, c, tmp);
        if (c < n-1 && Math.abs(a[r][c]-a[r][c+1]) <= tmp) res += floodfill(r, c+1, tmp);
        return res;
    }
}