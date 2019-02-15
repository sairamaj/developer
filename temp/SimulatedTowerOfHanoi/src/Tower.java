import java.util.Stack;

public class Tower {
	private Stack<Disc> discs = new Stack<Disc>();
	int poleNumber;
	int spacerWidth;
	
	Tower(int poleNumber, int spacerWidth){
		this.poleNumber = poleNumber;
		this.spacerWidth = spacerWidth;
	}
	void addDisc(Disc d) {
		this.discs.push(d);
	}
	
	Disc removeDisc() {
		return this.discs.pop();
	}
	
	void draw() {
		fillSpace();
		System.out.println(" =====");
		fillSpace();
		System.out.println("  " + this.poleNumber);
		fillSpace();
		System.out.println(" =====");
		for(int i=0; i<5; i++) {
			fillSpace();
			System.out.println( "  |");
		}

		Stack<Disc> temp = new Stack<Disc>();
		for(Disc d: this.discs) {
			temp.push(d);
		}
		
		while(!temp.empty()) {
			Disc d = temp.pop();
			d.draw(this.spacerWidth);
		}
	}
	
	void fillSpace() {
		for(int i=0; i<this.spacerWidth; i++) {
			System.out.print(" ");
		}
	}
}
