import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class PowerChains {
   static final int MAXN = 100;
    
    static class Number implements Comparable<Number> {
        double what;
        int[] origin;
        
        public Number(Number parent, double value, int extra) {
            if (extra < 0) {
                origin = parent.origin;
                what = value;
                return;
            }
            if (parent != null) {
                origin = new int[parent.origin.length + 1];
                System.arraycopy(parent.origin, 0, origin, 1, parent.origin.length);
            } else {
                origin = new int[1];
            }
            origin[0] = extra;
            what = value;
        }

        public int compareTo(Number number) {
            return Double.compare(what, number.what);
        }
        
        public String toString() {
            StringBuilder b = new StringBuilder();
            b.append(what);
            for (int x : origin) b.append(" " + x);
            return b.toString();
        }
    }

   public static void main(String[] args) {
      Number[] interesting = new Number[MAXN];
      for (int i = 0; i < MAXN; ++i) {
         interesting[i] = new Number(null, Math.log(i + 1), i + 1);
      }
      while (true) {
         Number[] pows = new Number[MAXN * interesting.length];
         for (int i = 1; i < interesting.length; ++i) {
            pows[i] = new Number(interesting[i], Math.log(interesting[i].what), -1);
         }
         pows[0] = pows[1];
         for (int b = 2; b <= MAXN; ++b) {
            double logb = Math.log(Math.log(b));
            for (int i = 0; i < interesting.length; ++i) {
               pows[(b - 1) * interesting.length + i] =
                     new Number(interesting[i], interesting[i].what + logb, b);
            }
         }
         Arrays.sort(pows);
         double maxDiff = 0.0;
         double minDiff = 1e100;
         double maxBase = 0.0;
         double needDiff = Math.log(10);
         List<Number> newInteresting = new ArrayList<Number>();
         newInteresting.add(new Number(null, 0.0, 1));
         boolean wasBig = true;
         for (int i = 0; i + 1 < pows.length; ++i) {
            double diff = (pows[i + 1].what - pows[i].what) / (pows[i + 1].what);
            if (Math.abs(diff) < 1e-13) {
                    if (diff > maxDiff) {
                        maxDiff = diff;
                    }
            } else {
                    if (diff < minDiff) {
                        minDiff = diff;
                    }
               double a = pows[i].what;
               double b = pows[i + 1].what;
               boolean big;
               if (b - a > 5)
                  big = true;
               else {
                  double by = Math.exp(b - a) - 1;
                  big = a + Math.log(by) > Math.log(needDiff);
               }
               if (!big) {
                  if (wasBig)
                     newInteresting.add(new Number(pows[i], Math.exp(pows[i].what), -1));
                  newInteresting.add(new Number(pows[i + 1], Math.exp(pows[i + 1].what), -1));
                  maxBase = Math.max(maxBase, pows[i + 1].what);
                  wasBig = false;
               } else {
                  wasBig = true;
               }
            }
         }
         System.out.println(newInteresting.size() + " " + maxDiff + " " + Math.exp(maxBase) + " " + minDiff);
         if (newInteresting.size() == interesting.length) break;
         interesting = new Number[newInteresting.size()];
         for (int i = 0; i < interesting.length; ++i) {
            interesting[i] = newInteresting.get(i);
         }
      }
   }
}
