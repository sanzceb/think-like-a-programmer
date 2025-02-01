import static java.lang.System.out;

public class Main {
   public static void main(String [] args){ 
       for (int row = 1; row <= 4; row++) {
           for (int spaceNum = 1; spaceNum <= row - 1; spaceNum++) {
               out.print(' ');
           }
           for (int hashNum = 1; hashNum <= row; hashNum++) {
               out.print('#');
           }
           for(int spaceNum = 1; spaceNum <= 16 - 4 * row; spaceNum++) {
               out.print(' ');
           }
           for (int hashNum = 1; hashNum <= row; hashNum++) {
               out.print('#');
           }
           out.print('\n');
       }
       
       for (int row = 1; row <= 4; row++) {
           for (int spaceNum = 1; spaceNum <= 4 - row; spaceNum++) {
               out.print(' ');
           }
           for (int hashNum = 1; hashNum <= 5 - row; hashNum++) {
               out.print('#');
           }
           for (int spaceNum = 1; spaceNum <= 4 * row - 4; spaceNum++) {
               out.print(' ');
           }
           for (int hashNum = 1; hashNum <= 5 - row; hashNum++) {
               out.print('#');
           }
           out.print('\n');
       }
   } 
}
