import java.util.HashMap;

public class FakeCantor {
  private final HashMap<String, Float> rates = new HashMap<>() {{
    put("USD", 1.0366f);
    put("GBP", 0.87063f);
    put("CHF", 0.9881f);
    put("JPY", 145.12f);
  }};
  public float euroToRate(String currency) {
    return this.rates.get(currency);
  }
  public FakeCantor() {
  }

}

public interface Currency {
  Currency addedCurrency(float value, String currency);
  Currency subtractedCurrency(float value, String currency);
  String abbreviation();
  String symbol();
  String balance();
  float toDollarExchangeRate();
}


public class Euro implements Currency {
	private final float euros;
	public Euro(float euros) {this.euros = euros;}
	@Override
	public String abbrebiation() {return "EUR";}
	@Override
	public String symbol() {return "€";}
	@Override
	public String balance() {return euros + "€";}
	@Override
	public float toDollarExchangeRate() {;}
	@Override
	Euro addedCurrency(float value) {return new Euro(this.euros + this.value * toDollarExchangeRate()) ;}
  
}


public class Main {
  public static void main(String[] args) {
  Euro one = new Euro(1.00f);
  Euro plus = one.addedCurrency();
  System.out.println(plus.balance());
  }
}
