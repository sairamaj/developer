
public class DiscManager {
	private static Disc small = new Disc(5);
	private static Disc medium = new Disc(10);
	private static Disc large = new Disc(15);
	
	static Disc getLarge() {
		return large;
	}
	
	static Disc getMedium() {
		return medium;
	}
	
	static Disc getSmall() {
		return small;
	}
}
