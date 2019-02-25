
public class DiscManager {
	Disc getSmall() {
		System.out.println("returning small");
		return new Disc();
	}
	
	Disc getMedium() {
		System.out.println("returning medium");
		return null;
	}
	
	Disc getLarge() {
		System.out.println("returning large");
		return null;
	}
}
