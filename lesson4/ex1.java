interface Animal {
	Animal run(float speed);
}
 
public class Lion implements Animal {
	private final String colour;
	private boolean sleep;
	@Override
	public Lion run(float speed) { return new Lion(this->sleep = false); }
}

 public class Main {
	public static void main (String[] args)
	{
		Lion myLion = new Lion(true);
		Lion myLion2 = myLion.run(10.00f);
	}
}
