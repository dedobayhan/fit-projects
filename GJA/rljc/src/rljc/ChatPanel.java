/*
 * Project: RLJC - Really Lightweight Jabber Client
 * Author:  Petr Zemek, xzemek02@stud.fit.vutbr.cz
 * 
 * Copyright (C) 2009 Petr Zemek
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

package rljc;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.KeyEvent;
import java.beans.PropertyVetoException;

/**
 * Panel for handling a chat.
 */
public class ChatPanel extends javax.swing.JPanel implements IUserChatHandler {
	
	/** Name of the application user. */
	private static final String APP_USER_NAME = "Me";
	/** Font. */
	private static final Font textFont = new Font("Serif", Font.BOLD, 12);
	
	/** Listener that wants to be updated if the chat gets closed. */
	private IChatPanelHandler chatHandlerClosedListener = null;
	/** User chat. */
	private UserChat userChat = null;
	
	/**
	 * Creates new form ChatPanel.
	 */
	public ChatPanel() {
		initComponents();
		
		chatWindow.setFont(textFont);
		chatWindow.setForeground(Color.black);
		chatWindow.setEditable(false);
		messageToSent.setFont(textFont);
		messageToSent.setForeground(Color.black);
		chatWindow.setText("");
		
		// Maximize the internal frame
		internalFrame.setMaximizable(true);
		try {
			internalFrame.setMaximum(true);
		} catch (PropertyVetoException ex) {
			Logger.getLogger().info("Internal frame cannot me maximized: " + ex);
		}
		internalFrame.setMaximizable(false);
	}
	
	/**
	 * Constructs a ChatPanel object.
	 * 
	 * @param chatClosed Object that wants to be informed when the chat is closed.
	 */
	public ChatPanel(IChatPanelHandler chatHandlerClosed) {
		this();
		
		chatHandlerClosedListener = chatHandlerClosed;
	}
	
	public void chatCreated(UserChat chat) {
		userChat = chat;
		
		internalFrame.setTitle(chat.getUser());
	}

	public void chatError(UserChat chat, String errMessage) {
		Dialogs.displayErrorMessage(errMessage, "Chat error:");
	}

	public void messageReceived(UserChat chat, String message) {
		synchronized (this) {
			chatWindow.setText(chatWindow.getText() +
				"<" + chat.getUser() + ">: " + message + "\n");
		}
		
		// Inform the listener
		if (chatHandlerClosedListener != null) {
			chatHandlerClosedListener.chatPanelMessageReceived(this);
		}
	}

	public void chatClosed(UserChat chat) {
		// Inform the listener
		if (chatHandlerClosedListener != null) {
			chatHandlerClosedListener.chatPanelClosed(this);
		}
	}
	
	/**
	 * Closes the panel (and underlying chat).
	 */
	public void close() {
		if (userChat != null) {
			userChat.closeChat();
			userChat = null;
			internalFrame.dispose();
		}
	}
	
	/**
	 * Returns user chat of this handler (can return null). 
	 */
	 public UserChat getUserChat() {
		 return userChat;
	 }
	
	/**
	 * Sets whether the panel should be closable.
	 * 
	 * @param closable Should the panel be closable?
	 */
	public void setClosable(boolean closable) {
		internalFrame.setClosable(closable);
	} 
	 
	/**
	 * Gets focus.
	 */
	public void getFocus() {
		// Get focus on the message writing area
		internalFrame.requestFocus();
		messageToSent.requestFocus();
	}
	
	/** This method is called from within the constructor to
	 * initialize the form.
	 * WARNING: Do NOT modify this code. The content of this method is
	 * always regenerated by the Form Editor.
	 */
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        internalFrame = new javax.swing.JInternalFrame();
        messageToSentPane = new javax.swing.JScrollPane();
        messageToSent = new javax.swing.JTextArea();
        chatWindowPane = new javax.swing.JScrollPane();
        chatWindow = new javax.swing.JTextArea();

        setName("Form"); // NOI18N

        internalFrame.setClosable(true);
        internalFrame.setMaximizable(true);
        internalFrame.setDoubleBuffered(true);
        internalFrame.setMinimumSize(new java.awt.Dimension(20, 20));
        internalFrame.setName("internalFrame"); // NOI18N
        internalFrame.setVisible(true);
        internalFrame.addInternalFrameListener(new javax.swing.event.InternalFrameListener() {
            public void internalFrameOpened(javax.swing.event.InternalFrameEvent evt) {
            }
            public void internalFrameClosing(javax.swing.event.InternalFrameEvent evt) {
            }
            public void internalFrameClosed(javax.swing.event.InternalFrameEvent evt) {
                internalFrameInternalFrameClosed(evt);
            }
            public void internalFrameIconified(javax.swing.event.InternalFrameEvent evt) {
            }
            public void internalFrameDeiconified(javax.swing.event.InternalFrameEvent evt) {
            }
            public void internalFrameActivated(javax.swing.event.InternalFrameEvent evt) {
            }
            public void internalFrameDeactivated(javax.swing.event.InternalFrameEvent evt) {
            }
        });

        messageToSentPane.setDoubleBuffered(true);
        messageToSentPane.setMaximumSize(new java.awt.Dimension(32767, 50));
        messageToSentPane.setName("messageToSentPane"); // NOI18N

        messageToSent.setColumns(20);
        messageToSent.setRows(5);
        messageToSent.setDoubleBuffered(true);
        messageToSent.setMinimumSize(new java.awt.Dimension(0, 20));
        messageToSent.setName("messageToSent"); // NOI18N
        messageToSent.setPreferredSize(new java.awt.Dimension(150, 30));
        messageToSent.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                messageToSentKeyPressed(evt);
            }
        });
        messageToSentPane.setViewportView(messageToSent);

        internalFrame.getContentPane().add(messageToSentPane, java.awt.BorderLayout.PAGE_END);

        chatWindowPane.setDoubleBuffered(true);
        chatWindowPane.setName("chatWindowPane"); // NOI18N

        chatWindow.setColumns(20);
        chatWindow.setRows(5);
        chatWindow.setDoubleBuffered(true);
        chatWindow.setName("chatWindow"); // NOI18N
        chatWindowPane.setViewportView(chatWindow);

        internalFrame.getContentPane().add(chatWindowPane, java.awt.BorderLayout.CENTER);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(this);
        this.setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(internalFrame, javax.swing.GroupLayout.PREFERRED_SIZE, 400, javax.swing.GroupLayout.PREFERRED_SIZE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(internalFrame, javax.swing.GroupLayout.PREFERRED_SIZE, 300, javax.swing.GroupLayout.PREFERRED_SIZE)
        );
    }// </editor-fold>//GEN-END:initComponents
	
	/**
	 * Key was pressed in the message to sent area.
	 *
	 * @param evt Key was pressed event
	 */
	private void messageToSentKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_messageToSentKeyPressed
		if (userChat == null) {
			return;
		}

		// Check whether enter was pressed and there is some text to be sent
		if (evt.getKeyCode() == KeyEvent.VK_ENTER && messageToSent.getText().length() > 0) {
			// Send the message
			boolean messageSent = userChat.sendMessage(messageToSent.getText());
			if (messageSent) {
				synchronized (this) {
					chatWindow.setText(chatWindow.getText() +
							"<" + APP_USER_NAME + ">: " + messageToSent.getText() + "\n");
					messageToSent.setText("");
				}
				evt.consume();
			}
		}
	}//GEN-LAST:event_messageToSentKeyPressed

	/**
	 * Internal frame is closed.
	 * 
	 * @param evt Internal frame event.
	 */
	private void internalFrameInternalFrameClosed(javax.swing.event.InternalFrameEvent evt) {//GEN-FIRST:event_internalFrameInternalFrameClosed
		close();
	}//GEN-LAST:event_internalFrameInternalFrameClosed

	/**
	 * Internal frame was closed event.
	 * 
	 * @param evt Internal frame event.
	 */	
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextArea chatWindow;
    private javax.swing.JScrollPane chatWindowPane;
    private javax.swing.JInternalFrame internalFrame;
    private javax.swing.JTextArea messageToSent;
    private javax.swing.JScrollPane messageToSentPane;
    // End of variables declaration//GEN-END:variables
	
}
