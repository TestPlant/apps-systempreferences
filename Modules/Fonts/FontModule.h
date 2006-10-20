/* (c) Ingolf Jandt, September 2006 
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02111 USA.
 */

#include <AppKit/AppKit.h>
#include <Foundation/Foundation.h>

#ifdef __APPLE__
  #include <GSPreferencePanes/PreferencePanes.h>
#else
  #include <PreferencePanes/PreferencePanes.h>
#endif

@interface FontModule :  NSPreferencePane
{
  id keyPopup;
  id setButton;
  id previewTextField;

  NSArray *fontKeys;
  NSDictionary *fontDescriptions;
}
- (void) keyPopupAction: (id)sender;
- (void) setButtonAction: (id)sender;
- (void) updatePreview;
- (void) changeFont: (id) sender;
- (void) willUnselect;
- (void) dealloc;
@end


/*Category to catch SystemPreferences' changeFont: action.
 *Workaround for PreferencePanes' not recieving the event.
 *Thanks to Enrico Sersale for the idea.
 */
@interface SystemPreferences : NSObject
{}
@end

@interface SystemPreferences (FontMethods)
- (void)changeFont:(id)sender;
@end
