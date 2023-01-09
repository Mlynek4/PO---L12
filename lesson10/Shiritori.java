import java.util.ArrayList;

public class Shiritori {
    private boolean game_over = false;
    ArrayList<String> words = new ArrayList<String>();
    
    public void play(String arg) {
        words.add(arg);
    }
    
    public void restart() {
        game_over = false;
        words = null;
    }
    
    public void printWords() {
        System.out.println(words);
    }
    
}
