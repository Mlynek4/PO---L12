
public class Main
{
    public static void main(String[] args) {
        Shiritori my_shiritori = new Shiritori();
        my_shiritori.play("apple");
        my_shiritori.play("ear");
        my_shiritori.printWords();
        my_shiritori.restart();
        my_shiritori.printWords();
    }
}
