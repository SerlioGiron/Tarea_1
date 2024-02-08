/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package poligonos;

import java.awt.*;
import java.util.ArrayList;
import javax.swing.*;

/**
 *
 * @author serli
 */
public class jRisk extends JFrame {

    private JFrame mainMap;
    private Polygon poly;

    public jRisk(ArrayList<Integer> xlist, ArrayList<Integer> ylist) {

        initComponents(xlist, ylist);

    }

    private void initComponents(ArrayList<Integer> xlist, ArrayList<Integer> ylist) {

        mainMap = new JFrame();
        mainMap.setResizable(false);

        mainMap.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        int xPoly[] = xlist.stream().mapToInt(i -> i).toArray();
        int yPoly[] = ylist.stream().mapToInt(i -> i).toArray();
//        int xPoly[] = {400, 10, 362, 81, 265, 196};
//        int yPoly[] = {200, 140, 316, 40, 389, 1};

        poly = new Polygon(xPoly, yPoly, xPoly.length);
        JPanel p = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                g.setColor(Color.BLUE);
                g.drawPolygon(poly);
            }

            @Override
            public Dimension getPreferredSize() {
                return new Dimension(800, 600);
            }
        };
        mainMap.add(p);
        mainMap.pack();
        mainMap.setVisible(true);

    }
}
