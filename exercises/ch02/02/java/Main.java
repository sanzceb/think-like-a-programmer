import static java.lang.System.out;

class Main {
    public static void main(String[] args) {
        for (int row = 1; row <= 4; row++) {
            for (int spaceNum = 1; spaceNum <= 4 - row; spaceNum++) {
               out.print(' ');
            }
            for (int hashNum = 1; hashNum <= row * 2; hashNum++) {
                out.print('#');
            }
            out.print('\n');
        }

        for (int row = 1; row <= 4; row++){
            for (int spaceNum = 1; spaceNum < row; spaceNum++) {
                out.print(' ');
            }
            for (int hashNum = 1; hashNum <= 10 - 2 * row; hashNum++){
                out.print('#');
            }
            out.print('\n');
        }
    }
}