
public final class Characters implements Sequence {
    private final String x;
    
    public Characters(String x){
        this.x = x;
    }
    
    @Override
    public String printedSeq() {
        return this.x;
    }

}
