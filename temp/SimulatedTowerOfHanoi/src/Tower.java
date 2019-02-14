import java.util.Stack;

public class Tower {
	private Stack<Disc> discs = new Stack<Disc>();
	int poleNumber;
	
	Tower(int poleNumber){
		this.poleNumber = poleNumber;
	}
	void addDisc(Disc d) {
		this.discs.push(d);
	}
	
	Disc removeDisc() {
		return this.discs.pop();
	}
	
	void draw() {
		System.out.println(" =====");
		System.out.println("  " + this.poleNumber);
		System.out.println(" =====");
		for(int i=0; i<5; i++) {
			System.out.println( "  |");
		}

		while(!this.discs.empty()) {
			Disc d = discs.pop();
			d.draw();
		}
		
	}
}
