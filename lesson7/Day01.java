import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;


public class Read {
    public static void main(String[] args) {
        int cal = 0, max = 0, optelf = 0, elf = 1;
        try{
            Scanner scanner = new Scanner(new File("Day01.txt"));
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                if (line.isEmpty()){
                    if(cal>max){
                        max = cal;
                        optelf = elf;
                    }
                    cal = 0;
                    elf += 1;
                }
                else{
                    cal+=Integer.parseInt(line);
                }   
            }
        }
        catch (FileNotFoundException e) {
                e.printStackTrace();
        }
        System.out.println("Carring most is elf number " + optelf);
        System.out.println("He is carring " + max);
    }
}
