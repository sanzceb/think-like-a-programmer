import static java.lang.System.out;

class Main {
    public static void main(String args[]) {
        //First Pyramid
        for (int row = 1; row <= 4; row++) {
            for (int spaceNum = 1; spaceNum <= 9 - 2 * row; spaceNum++) {
                out.print(' ');
            }
            for (int hashNum = 1; hashNum <= 4 * row - 2; hashNum++) {
                out.print('#');
            }
            out.print('\n');
        }
        
        for (int row = 1; row <= 3; row++) {
            for (int hashNum = 1; hashNum <= 10 - 2 * row; hashNum++) {
                out.print('#');
            }
            for (int spaceNum = 1; spaceNum <= 4 * row - 4; spaceNum++) {
                out.print(' ');
            }
            for (int hashNum = 1; hashNum <= 10 - 2 * row; hashNum++) {
                out.print('#');
            }
            out.print('\n');
        }
    
        for (int row = 1; row <= 2; row++) {
            for (int hashNum = 1; hashNum <= 4 - row; hashNum++){
                out.print('#');
            }
            for (int spaceNum = 1; spaceNum <= 3; spaceNum++) {
                out.print(' ');
            }
            for (int hashnum = 1; hashnum <= 2 * row + 2; hashnum++) {
                 out.print('#');
            }
            for (int spaceNum = 1; spaceNum <= 3; spaceNum++) {
                out.print(' ');
            }
            for (int hashNum = 1; hashNum <= 4 - row; hashNum++){
                out.print('#');
            }
            out.print('\n');
        }

        for (int row = 1; row <= 3; row++) {
            for (int hashNum = 1; hashNum <= row; hashNum++){
                out.print('#');
            }
            for (int spaceNum = 1; spaceNum <= 3; spaceNum++) {
                out.print(' ');
            }
            for (int hashnum = 1; hashnum <= 10 - 2 * row; hashnum++) {
                 out.print('#');
            }
            for (int spaceNum = 1; spaceNum <= 3; spaceNum++) {
                out.print(' ');
            }
            for (int hashNum = 1; hashNum <= row; hashNum++){
                out.print('#');
            }
            out.print('\n');
        }

        for (int row = 1; row <= 3; row++) {
            for (int hashnum = 1; hashnum <= 2 * row + 2; hashnum++) {
                out.print('#');
            }
            for (int spacenum = 1; spacenum <= 12 - 4 * row; spacenum++) {
                out.print(' ');
            }
            for (int hashnum = 1; hashnum <= 2 * row + 2; hashnum++) {
                out.print('#');
            }
            out.print('\n');
        }

        // Second Pyramid
        for (int row = 1; row <= 4; row++) {
            for (int spacenum = 1; spacenum <= 2 * row - 1; spacenum++) {
                out.print(' ');
            }
            for (int hashnum = 1; hashnum <= 18 - 4 * row; hashnum++) {
                out.print('#');
            }
            out.print('\n');
        }
    }
}
