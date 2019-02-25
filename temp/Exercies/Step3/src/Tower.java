
public class Tower {
	Disc disc;
	void draw() {
		System.out.println("  Tower  ");
		for(int i=0; i<3; i++) {
			System.out.println("    |");
		}
		this.disc.draw();
	}
	
	void addDisc(Disc disc) {
		this.disc = disc;
	}
}
