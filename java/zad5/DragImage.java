import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import java.io.File;
import java.io.IOException;
import java.net.URL;

import javax.imageio.ImageIO;
import javax.swing.JComponent;
import javax.swing.JFrame;

class DragImage extends JComponent implements MouseMotionListener {
	private static final long serialVersionUID = -4565157109448532709L;
	static int imageWidth = 100, imageHeight = 100;
	int imageX, imageY;
	Image image;

	public DragImage(Image i) {
		image = i;
		addMouseMotionListener(this);
	}

	public void mouseDragged(MouseEvent e) {
		imageX = e.getX();
		imageY = e.getY();
		repaint();
	}

	public void mouseMoved(MouseEvent e) {
	}

	public void paint(Graphics g) {
		Graphics2D g2 = (Graphics2D) g;

		g2.drawImage(image, imageX, imageY, this);
	}

	public static void main(String[] args) {
		Image image = null;
		try {
			URL url = new URL("http://149.156.41.217/Piotr.Oramus/dydaktyka/sowaWnocy.png");
			image = ImageIO.read(url);
		} catch (IOException e) {
			e.printStackTrace();
		}
		image = image.getScaledInstance(imageWidth, imageHeight,
				Image.SCALE_DEFAULT);
		JFrame frame = new JFrame("DragImage");
		frame.getContentPane().add(new DragImage(image));
		frame.setSize(300, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
	}
}
