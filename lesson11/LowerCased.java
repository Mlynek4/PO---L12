
public class LowerCased implements Sequence {
	private final Sequence s;
	
	public LowerCased(Sequence s) {
		this.s = s;
	}
	
	@Override
	public String printedSeq() {
		return this.s.printedSeq().toLowerCase();
	}

}
