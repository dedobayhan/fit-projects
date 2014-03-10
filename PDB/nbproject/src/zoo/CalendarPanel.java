/**
 *  Project:  PDB 2008
 *  Authors:  Ondrej Lengal,   xlenga00@stud.fit.vutbr.cz
 *            Libor Polcak,    xpolca03@stud.fit.vutbr.cz
 *            Boris Prochazka, xproch63@stud.fit.vutbr.cz
 *            Petr Zemek,      xzemek02@stud.fit.vutbr.cz
 *
 * @brief Graphical wrapper for the Calendar class.
 *
 */

package zoo;

import java.util.Date;

/**
 * @brief Graphical wrapper for the Calendar class.
 */
public class CalendarPanel extends javax.swing.JPanel {

	/// Underlying calendar.
	private Calendar underlyingCalendar = Calendar.getInstance();

	/**
	 * @brief Default constructor.
	 */
	public CalendarPanel() {
		initComponents();
	}

	/**
	 * @brief Returns the currently set date.
	 */
	public Date getDate() {
		return underlyingCalendar.getDate();
	}

	/**
	 * @brief Sets a new date.
	 *
	 * @param date Date to be set.
	 */
	public void setDate(Date date) {
		underlyingCalendar.setDate(date);
		graphicalCalendar.setDate(date);
	}

	/** This method is called from within the constructor to
	 * initialize the form.
	 * WARNING: Do NOT modify this code. The content of this method is
	 * always regenerated by the Form Editor.
	 */
	@SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        graphicalCalendar = new com.toedter.calendar.JCalendar();

        setName("Form"); // NOI18N

        graphicalCalendar.setName("graphicalCalendar"); // NOI18N
        graphicalCalendar.addPropertyChangeListener(new java.beans.PropertyChangeListener() {
            public void propertyChange(java.beans.PropertyChangeEvent evt) {
                graphicalCalendarPropertyChange(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(graphicalCalendar, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(graphicalCalendar, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
        );
    }// </editor-fold>//GEN-END:initComponents

	private void graphicalCalendarPropertyChange(java.beans.PropertyChangeEvent evt) {//GEN-FIRST:event_graphicalCalendarPropertyChange
		// Underlying calendar date have to be changed accordingly
		underlyingCalendar.setDate(graphicalCalendar.getDate());
	}//GEN-LAST:event_graphicalCalendarPropertyChange

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private com.toedter.calendar.JCalendar graphicalCalendar;
    // End of variables declaration//GEN-END:variables
}
