import static java.lang.System.out;

class Main {
    public static void main(String [] args) {
        for (int i = 0; i < 4; i++) {

            for (int j = 0; j < i; j++){
               out.print(' ');
            }

            for (int j = 0; j < 8 - 2 * i; j++) {
               out.print('#');
            }

            for (int j = 0; j < i; j++){
               out.print(' ');
            }

            out.print('\n');
        }
    }
}
