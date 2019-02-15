
public class Gamer {
	Tower[] towers;
	int numberOfTowers;
	int maxTowers = 3;
	
	Gamer(int numberOfTowers) throws Exception {
		if( numberOfTowers < 0) {
			throw new Exception("Number of towers has to b greater than zero.");
		}
		if( numberOfTowers > maxTowers) {
			throw new Exception("Cannot be " + maxTowers + " ");
		}
		
		this.towers = new Tower[numberOfTowers];
		this.numberOfTowers = numberOfTowers;
	}
	
	void create() {
		for(int i=0; i<numberOfTowers; i++) {
			towers[i] = new Tower(i+1, 10 + i*10);
		}
		
		towers[0].addDisc(DiscManager.getLarge());
		towers[0].addDisc(DiscManager.getMedium());
		towers[0].addDisc(DiscManager.getSmall());
		draw();
	}
	
	void move(int from, int to) {
		if( from <= 0) {
			System.out.println("from should be more than 0");
			return;
		}
		
		if( to >numberOfTowers) {
			System.out.println("to should be less than " + this.numberOfTowers);
			return;
		}
		
		Disc disc = towers[from-1].removeDisc();
		towers[to-1].addDisc(disc);
		draw();
	}
	
	private void draw() {
		for(int i=0; i<numberOfTowers; i++) {
			System.out.println("");
			towers[i].draw();
		}
	}
}
