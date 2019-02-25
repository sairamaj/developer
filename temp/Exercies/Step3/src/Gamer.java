
public class Gamer {
	void create() {
		System.out.println("creating game");
		Tower t = new Tower();
		DiscManager discManager = new DiscManager();
		t.addDisc(discManager.getSmall());
		t.draw();
	}
	
	void move(int from, int to) {
		System.out.println("moving " + from + " to " + to);
	}
}
