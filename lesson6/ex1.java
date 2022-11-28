public class Relation {
	private Relation() {
        throw new UnsupportedOperationException();
    }
    private int a;
    private int b;
	public int max() { 
	    a = this.a;
	    b = this.b;
	    return a > b ? a : b;
	}
	public int min() { 
	    a = this.a;
	    b = this.b;
	    return a < b ? a : b;
	}
	public int avg() { 
	    a = this.a;
	    b = this.b;
	    return (a + b) / 2;
	}
	public Relation(int a,int b) { this.a = a; this.b =b; }
}

 public class Main {
	public static void main (String[] args)
	{
	    Relation myRelation = new Relation(5,7);
		System.out.println(myRelation.max());
		System.out.println(myRelation.min());
		System.out.println(myRelation.avg());
	}
}
