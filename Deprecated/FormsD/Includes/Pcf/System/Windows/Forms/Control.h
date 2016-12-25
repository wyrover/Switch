/// @file
/// @brief Contains Pcf::System::Windows::Forms::Control class.
#pragma once

#include <Pcf/Ref.h>
#include <Pcf/System/Console.h>
#include <Pcf/System/EventArgs.h>
#include <Pcf/System/String.h>
#include <Pcf/System/Collections/Generic/List.h>
#include <Pcf/System/Collections/Concurrent/ConcurrentQueue.h>
#include <Pcf/System/Drawing/Color.h>
#include <Pcf/System/Drawing/Font.h>
#include <Pcf/System/Drawing/Graphics.h>
#include <Pcf/System/Drawing/Image.h>
#include <Pcf/System/Drawing/Point.h>
#include <Pcf/System/Drawing/Size.h>
#include <Pcf/System/Drawing/SizeF.h>

#include "../../ComponentModel/Component.h"
#include "AnchorStyles.h"
#include "ControlEventHandler.h"
#include "Cursor.h"
#include "Cursors.h"
#include "DockStyle.h"
#include "DragEventHandler.h"
#include "GiveFeedbackEventHandler.h"
#include "HelpEventHandler.h"
#include "ImageLayout.h"
#include "InvalidateEventHandler.h"
#include "KeyEventHandler.h"
#include "KeyPressEventHandler.h"
#include "MethodInvoker.h"
#include "MouseEventHandler.h"
#include "PaintEventHandler.h"
#include "Timer.h"
#include "UICuesEventHandler.h"

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace FormsD {
        using LayoutEventArgs = System::EventArgs;

        using LayoutEventHandler = System::EventHandler;
        
        /// @cond
        //class IWidget;
        class IWidget pcf_interface {
        public:
          class WidgetEventArgs : public EventArgs {
          public:
            WidgetEventArgs() {}
            WidgetEventArgs(int32 event, bool isHandled) : event(event), isHandled(isHandled) {}
            WidgetEventArgs(const WidgetEventArgs& eventArgs) : event(eventArgs.event), isHandled(eventArgs.isHandled) {}
            
            Property<int32, ReadOnly> Event {
              pcf_get {return this->event;}
            };
            
            Property<bool> IsHandled {
              pcf_get {return this->isHandled;},
              pcf_set {this->isHandled = value;}
            };
            
          private:
            int32 event = 0;
            bool isHandled = false;
          };

          using WidgetEventHandler = Delegate<void, const object&, WidgetEventArgs&>;

          WidgetEventHandler EventHandled;
          EventHandler Paint;
          EventHandler Callback;

          virtual void Draw() = 0;
        };
        /// @endcond
        
        /// @brief Defines the base class for controls, which are components with visual representation.
        /// @remarks To create your own control class, inherit from the UserControl, Control classes, or from the other Windows Forms provided controls. For more information about authoring custom controls, see Developing Custom Windows Forms Controls with the .NET Framework.
        /// @remarks The Control class implements very basic functionality required by classes that display information to the user. It handles user input through the keyboard and pointing devices. It handles message routing and security. It defines the bounds of a control (its position and size), although it does not implement painting. It provides a window handle (hWnd).
        /// @remarks Windows Forms controls use ambient properties so child controls can appear like their surrounding environment. An ambient property is a control property that, if not set, is retrieved from the parent control. If the control does not have a Parent, and the property is not set, the control attempts to determine the value of the ambient property through the Site property. If the control is not sited, if the site does not support ambient properties, or if the property is not set on the AmbientProperties, the control uses its own default values. Typically, an ambient property represents a characteristic of a control, such as BackColor, that is communicated to a child control. For example, a Button will have the same BackColor as its parent Form by default. Ambient properties provided by the Control class include: Cursor, Font, BackColor, ForeColor, and RightToLeft.
        /// @note To make your Windows Forms application support visual styles, be sure to set the FlatStyle property to System and include a manifest with your executable. A manifest is an XML file that is included either as a resource within your application executable or as a separate file that resides in the same directory as the executable file. For an example of a manifest, see the Example section of the FlatStyle enumeration. For more information about using visual styles, see Visual Styles.
        /// @note Windows Forms has accessibility support built in, and provides information about your application that enables it to work with accessibility client applications such as screen enlarger and reviewer utilities, voice input utilities, on-screen keyboards, alternative input devices, and keyboard enhancement utilities. Sometimes you will want to provide additional information to accessibility client applications. There are two ways of providing this additional information. You can set the AccessibleName, AccessibleDescription, AccessibleDefaultActionDescription, and AccessibleRole property values, which will be reported to accessibility client applications. This method is typically used to provide limited accessibility information for existing controls. Alternatively, you can write your own class deriving from the AccessibleObject or Control.ControlAccessibleObject classes, providing as much accessibility information as needed.
        /// @note To maintain better performance, do not set the size of a control in its constructor. The preferred method is to override the DefaultSize property.
        /// @note Do not add data bindings for a Control in its constructor. Doing so will cause errors in code generation and can cause unwanted behavior.
        /// @note The majority of the controls in the System::Windows::Forms namespace use the underlying Windows common control as a base to build on. For more information about the Windows common controls, see General Control Reference.
        /// @note To identify Windows Forms controls from a separate process, use a standard SendMessage call to pass the WM_GETCONTROLNAME message. WM_GETCONTROLNAME is independent of the language and Windows hierarchy. For more information, see the "Recommended Solution for Windows Forms" topic in Automating Windows Forms::
        /// @note Use the InvokeRequired property to synchronize access to the control from multiple threads. For more information about multithreaded Windows Forms controls, see How to: Make Thread-Safe Calls to Windows Forms Controls
        class Control : public System::ComponentModel::Component {
        public:
          /// @brief Represents a collection of Control objects.
          /// @remarks The Add, Remove, and RemoveAt methods enable you to add and remove individual controls from the collection. You can also use the AddRange or Clear methods to add or remove all the controls from the collection.
          /// @remarks You can determine if a Control is a member of the collection by passing the control into the Contains method. To get the index value of the location of a Control in the collection, pass the control into the IndexOf method. The collection can be copied into an array by calling the CopyTo method.
          /// @code
          /// // Remove the RadioButton control if it exists.
          /// void RemoveButtonClick(const object& sender, const System::EventArgs& e) {
          ///   if (panel1.Controls().Contains(removeButton)) {
          ///     panel1.Controls().Remove(removeButton);
          ///   }
          /// }
          /// @endcode
          class ControlCollection : public Pcf::System::Collections::Generic::List<Reference<Control>> {
          public:
            ControlCollection(Control& parent) : parent(&parent) {
            }

            virtual void Add(const Reference<Control>& value) {
              this->AddControl(const_cast<Control&>(value()));
            }

            virtual void Add(const Control& value) {
              this->AddControl(const_cast<Control&>(value));
            }

            virtual bool Remove(const Reference<Control>& value) {
              return this->RemoveControl(const_cast<Control&>(value()));
            }

            virtual bool Remove(const Control& value) {
              return this->RemoveControl(const_cast<Control&>(value));
            }

            void AddControl(Control& control);

            bool RemoveControl(Control& control);

            Control* parent;
          };
          
          static Property<System::Drawing::Color, ReadOnly> DefaultBackColor;
          static Property<System::Drawing::Color, ReadOnly> DefaultForeColor;
          static Property<System::Drawing::Font, ReadOnly> DefaultFont;

          
          /// @brief Initializes a new instance of the Control class with default settings.
          /// @remarks The Control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
          Control();
          
          /// @brief Initializes a new instance of the Control class with default settings.
          /// @remarks The Control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
          Control(UniquePointer<IWidget> widget);

          /// @brief Initializes a new instance of the Control class with specific text.
          /// @param text The text displayed by the control.
          /// @remarks The Control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
          /// @remarks This version of the Control constructor sets the initial Text property value to the text parameter value.
          Control(const string& text) {}

          /// @brief Initializes a new instance of the Control class as a child control, with specific text.
          /// @param parent The Control to be the parent of the control.
          /// @param text The text displayed by the control.
          /// @remarks The Control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
          /// @remarks This version of the Control constructor sets the initial Text property value to the text parameter value. The constructor also adds the control to the parent control's Control::ControlCollection.
          Control(const Control& parent, const string& text) : parent(const_cast<Control*>(&parent)) {}

          /// @brief Initializes a new instance of the Control class with specific text, size, and location.
          /// @param text The text displayed by the control.
          /// @param left The X position of the control, in pixels, from the left edge of the control's container. The value is assigned to the Left property.
          /// @param top The Y position of the control, in pixels, from the top edge of the control's container. The value is assigned to the Top property.
          /// @param width The height of the control, in pixels. The value is assigned to the Height property.
          /// @param height The width of the control, in pixels. The value is assigned to the Width property.
          /// @remarks The Control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
          /// @remarks This version of the Control constructor sets the initial Text property value to the text parameter value. The initial Size and Location of the control are determined by the left, top, width and height parameter values.
          /// @note To maintain better performance, do not set the size of a control in its constructor. The preferred method is to virtual the DefaultSize property.
          Control(const string& text, int32 left, int32 top, int32 width, int32 height) {}

          /// @brief Initializes a new instance of the Control class as a child control, with specific text, size, and location.
          /// @param parent The Control to be the parent of the control.
          /// @param text The text displayed by the control.
          /// @param left The X position of the control, in pixels, from the left edge of the control's container. The value is assigned to the Left property.
          /// @param top The Y position of the control, in pixels, from the top edge of the control's container. The value is assigned to the Top property.
          /// @param width The height of the control, in pixels. The value is assigned to the Height property.
          /// @param height The width of the control, in pixels. The value is assigned to the Width property.
          /// @remarks The Control class is the base class for all controls used in a Windows Forms application. Because this class is not typically used to create an instance of the class, this constructor is typically not called directly but is instead called by a derived class.
          /// @remarks This version of the Control constructor sets the initial Text property value to the text parameter value. The constructor also adds the control to the parent control's Control.ControlCollection. The initial Size and Location of the control are determined by the left, top, width and height parameter values.
          /// @note To maintain better performance, do not set the size of a control in its constructor. The preferred method is to virtual the DefaultSize property.
          Control(const Control& parent, const string& text, int32 left, int32 top, int32 width, int32 height) : parent(const_cast<Control*>(&parent)) {}

          /// @cond
          Control(const Control& control) : widget(control.widget), accessibleDefaultActionDescription(control.accessibleDefaultActionDescription), accessibleDescription(control.accessibleDescription),
          accessibleName(control.accessibleName), allowDrop(control.allowDrop), anchor(control.anchor), autoScrollOffset(control.autoScrollOffset), autoSize(control.autoSize),
          backgroundImage(control.backgroundImage), backgroundImageLayout(control.backgroundImageLayout), causesValidation(control.causesValidation), controls(control.controls),
          companyName(control.companyName), containsFocus(control.containsFocus), cursor(control.cursor), dock(control.dock), enabled(control.enabled), font(control.font), graphics(control.graphics),
          name(control.name), oldParent(control.oldParent), parentLocation(control.parentLocation), parentSize(control.parentSize), invoker(control.invoker) {
            this->Parent = *control.parent;
          }
          ~Control();
          /// @endcond

          /// @brief Gets or sets the default action description of the control for use by accessibility client applications.
          /// @param value The default action description of the control for use by accessibility client applications.
          /// @remarks An object's AccessibleDefaultActionDescription property describes the object's primary method of manipulation from the user's viewpoint. This property should be a verb or a short verb phrase.
          Property<const string&> AccessibleDefaultActionDescription {
            pcf_get->const string& {return this->accessibleDefaultActionDescription;},
            pcf_set {this->SetAccessibleDefaultActionDescription(value);}
          };
          
          /// @brief Gets or sets the description of the control used by accessibility client applications.
          /// @param value The description of the control used by accessibility client applications.
          /// @remarks An object's AccessibleDescription property provides a textual description about an object's visual appearance. The description is primarily used to provide greater context for low-vision or blind users, but can also be used for context searching or other applications.
          /// @remarks The AccessibleDescription property is needed if the description is not obvious, or if it is redundant based on the object's AccessibleName, AccessibleRole, State, and Value properties. For example, a button with "OK" would not need additional information, but a button that shows a picture of a cactus would. The AccessibleName, and AccessibleRole (and perhaps Help) properties for the cactus button would describe its purpose, but the AccessibleDescription property would convey information that is less tangible, such as "A button that shows a picture of a cactus."
          /// @remarks For more information about properties of accessible objects, see Content of Descriptive Properties.
          Property<const string&> AccessibleDescription {
            pcf_get->const string& {return this->accessibleDescription;},
            pcf_set {this->SetAccessibleDescription(value);}
          };

          /// @brief Gets or sets the name of the control used by accessibility client applications.
          /// @param value The name of the control used by accessibility client applications.
          /// @remarks The AccessibleName property is a label that briefly describes and identifies the object within its container, such as the text in a Button, the name of a MenuItem, or a label displayed next to a TextBox control.
          /// @remarks For more information about properties of accessible objects, see the "Content of Descriptive Properties.
          Property<const string&> AccessibleName {
            pcf_get->const string& {return this->accessibleName;},
            pcf_set {this->SetAccessibleName(value);}
          };

          /// @brief Gets or sets a value indicating whether the control can accept data that the user drags onto it.
          /// @param value true if drag-and-drop operations are allowed in the control; otherwise, false. The default is false.
          /// @remarks <b>Notes to Inheritors</b>
          /// @remarks When overriding the AllowDrop property in a derived class, use the base class's AllowDrop property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set accessors of the AllowDrop property; you can override only one if needed.
          Property<bool> AllowDrop {
            pcf_get {return this->allowDrop;},
            pcf_set {this->SetAllowDrop(value);}
          };

          /// @brief Gets or sets the edges of the container to which a control is bound and determines how a control is resized with its parent.
          /// @param value A bitwise combination of the AnchorStyles values. The default is Top and Left.
          /// @remarks Use the Anchor property to define how a control is automatically resized as its parent control is resized. Anchoring a control to its parent control ensures that the anchored edges remain in the same position relative to the edges of the parent control when the parent control is resized.
          /// @remarks You can anchor a control to one or more edges of its container. For example, if you have a Form with a Button whose Anchor property value is set to Top and Bottom, the Button is stretched to maintain the anchored distance to the top and bottom edges of the Form as the Height of the Form is increased.
          Property<AnchorStyles> Anchor {
            pcf_get {return this->anchor;},
            pcf_set {this->SetAnchor(value);}
          };

          /// @brief Gets or sets the edges of the container to which a control is bound and determines how a control is resized with its parent.
          /// @return A Point specifying the scroll location. The default is the upper-left corner of the control.
          Property<System::Drawing::Point> AutoScrollOffset {
            pcf_get {return this->autoScrollOffset;},
            pcf_set {this->SetAutoScrollOffset(value);}
          };

          /// @brief Infrastructure. This property is not relevant for this class.
          /// @param value true if enabled; otherwise, false.
          Property<bool> AutoSize {
            pcf_get {return this->autoSize;},
            pcf_set {
              if (this->autoSize != value) {
                this->SetAutoSize(value);
              }
            }
          };

          /// @brief Gets or sets the background color for the control.
          /// @param value A Color that represents the background color of the control. The default is the value of the DefaultBackColor property.
          /// @remarks The BackColor property does not support transparent colors unless the SupportsTransparentBackColor value of System::Windows::Forms::ControlStyles is set to true.
          /// @remarks The BackColor property is an ambient property. An ambient property is a control property that, if not set, is retrieved from the parent control. For example, a Button will have the same BackColor as its parent Form by default. For more information about ambient properties, see the AmbientProperties class or the Control class overview.
          /// @remarks <b>Notes to Inheritors</b>
          /// @remarks When overriding the BackColor property in a derived class, use the base class's BackColor property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set accessors of the BackColor property; you can override only one if needed.
          Property<System::Drawing::Color> BackColor {
            pcf_get {return this->backColor;},
            pcf_set {this->SetBackColor(value);}
          };

          /// @brief Gets or sets the background image displayed in the control.
          /// @param value An Image that represents the image to display in the background of the control.
          /// * Use the BackgroundImage property to place a graphic image onto a control.
          /// @note Images with translucent or transparent colors are not supported by Windows Forms controls as background images.
          /// @note This property is not supported on child controls whose RightToLeftLayout property is true.
          /// @note <b>Notes to Inheritors</b>
          /// @note When overriding the BackgroundImage property in a derived class, use the base class's BackgroundImage property to extend the base implementation. Otherwise, you must provide all the implementation. You are not required to override both the get and set accessors of the BackgroundImage property; you can override only one if needed.
          Property<const System::Drawing::Image&> BackgroundImage {
            pcf_get->const System::Drawing::Image& {return this->GetBackgroundImage();},
            pcf_set {this->SetBackgroundImage(value);}
          };

          /// @brief Gets or sets the background image layout as defined in the System::Windows::Forms::ImageLayout enumeration.
          /// @param value One of the values of ImageLayout (Center , None, Stretch, Tile, or Zoom). Tile is the default value.
          /// @exception InvalidEnumArgumentException The specified enumeration value does not exist.
          /// @remarks Use the BackgroundImageLayout property to specify the position and behavior of an image you have placed onto a control. BackgroundImageLayout takes effect only if the BackgroundImage property is set.
          /// @remarks You can increase performance for large images if you set BackgroundImageLayout to something other than Tile.
          Property<ImageLayout> BackgroundImageLayout {
            pcf_get {return this->GetBackgroundImageLayout();},
            pcf_set {this->SetBackgroundImageLayout(value);}
          };
          
          /*
          /// @brief Gets or sets the BindingContext for the control.
          /// @param binding A BindingContext for the control.
          /// @remarks The BindingContext of a Control is used to return a singleBindingManagerBase for all data-bound controls contained by the Control. The BindingManagerBase keeps all controls that are bound to the same data source synchronized. For example, setting the Position property of the BindingManagerBase specifies the item in the underlying list that all data-bound controls point to.
          /// @remarks For more information about creating a new BindingContext and assigning it to the BindingContext property, see the BindingContext.
          Property<System::Windows::Forms::BindingContext> BindingContext {
            pcf_get {return this->GetBindingContext();},
            pcf_set {this->SetBindingContext(value);}
          };
           */

          /// @brief Gets the distance, in pixels, between the bottom edge of the control and the top edge of its container's client area
          /// @param value An Int32 representing the distance, in pixels, between the bottom edge of the control and the top edge of its container's client area.
          /// @remarks The value of this property is equal to the sum of the Top property value, and the Height property value.
          /// @remarks The Bottom property is a read-only property. You can manipulate this property value by changing the value of the Top or Height properties or calling the SetBounds, SetBoundsCore, UpdateBounds, or SetClientSizeCore methods.
          Property<int32, ReadOnly> Bottom {
            pcf_get {return this->Location().Y() + this->Size().Height();;}
          };

          /// @brief Gets or sets the size and location of the control including its nonclient elements, in pixels, relative to the parent control.
          /// @param value A Rectangle in pixels relative to the parent control that represents the size and location of the control including its nonclient elements.
          /// @remarks The bounds of the control include the nonclient elements such as scroll bars, borders, title bars, and menus. The SetBoundsCore method is called to set the Bounds property. The Bounds property is not always changed through its set method so you should override the SetBoundsCore method to ensure that your code is executed when the Bounds property is set.
          Property<System::Drawing::Rectangle> Bounds {
            pcf_get {return Drawing::Rectangle(this->Location(), this->Size());},
            pcf_set {
              this->SuspendLayout();
              this->SetLocation(value.Location());
              this->SetSize(value.Size());
              this->ResumeLayout();
            }
          };

          /// @brief Gets a value indicating whether the ImeMode property can be set to an active value, to enable IME support.
          /// @return true in all cases.
          /// @remarks Derived classes can override this property to return false if IME is not supported.
          Property<bool, ReadOnly> CanEnableIme {
            pcf_get {return this->GetCanEnableIme();}
          };

          /// @brief Gets a value indicating whether the control can receive focus.
          /// @param value rue if the control can receive focus; otherwise, false.
          /// @remarks In order for a control to receive input focus, the control must have a handle assigned to it, and the Visible and Enabled properties must both be set to true for both the control and all its parent controls, and the control must be a form or the control's outermost parent must be a form.
          Property<bool, ReadOnly> CanFocus {
            pcf_get {return this->GetCanFocus();}
          };

          /// @brief Gets a value indicating whether the control can be selected.
          /// @param value true if the control can be selected; otherwise, false.
          /// @remarks This property returns true if the Selectable value of System::Windows::Forms::ControlStyles is set to true, is contained in another control, the control itself is visible and enabled, and all its parent controls are visible and enabled.
          /// @remarks The Windows Forms controls in the following list are not selectable and will return a value of false for the CanSelect property. Controls derived from these controls are also not selectable.
          Property<bool, ReadOnly> CanSelect {
            pcf_get {return this->GetCanSelect();}
          };
          
          /// @brief Gets or sets a value indicating whether the control causes validation to be performed on any controls that require validation when it receives focus.
          /// @param value true if the control causes validation to be performed on any controls requiring validation when it receives focus; otherwise, false. The default is true.
          /// @remarks If the CausesValidation property is set to false, the Validating and Validated events are suppressed.
          /// @remarks The CausesValidation property value is typically set to false for controls such as a Help button.
          Property<bool> CausesValidation {
            pcf_get {return this->GetCausesValidation();},
            pcf_set {this->SetCausesValidation(value);}
          };
          
          /// @brief Gets the rectangle that represents the client area of the control.
          /// @param value A Rectangle that represents the client area of the control.
          /// @remarks The client area of a control is the bounds of the control, minus the nonclient elements such as scroll bars, borders, title bars, and menus.
          /// @remarks Because client coordinates are relative to the upper-left corner of the client area of the control, the coordinates of the upper-left corner of the rectangle returned by this property are (0,0). You can use this property to obtain the size and coordinates of the client area of the control for tasks such as drawing on the surface of the control.
          /// @remarks For more information about drawing on controls, see Rendering a Windows Forms Control.
          Property<System::Drawing::Rectangle, ReadOnly> ClientRectangle {
            pcf_get {return System::Drawing::Rectangle(System::Drawing::Point(0, 0), this->clientSize);}
          };
          
          /// @brief Gets or sets the height and width of the client area of the control.
          /// @return A Size that represents the dimensions of the client area of the control.
          /// @remarks The client area of a control is the bounds of the control, minus the nonclient elements such as scroll bars, borders, title bars, and menus. The SetClientSizeCore method is called to set the ClientSizeproperty. The ClientSize property is not always changed through its set method so you should override the SetClientSizeCore method to ensure that your code is executed when the ClientSize property is set.
          /// @remarks The Size.Width and Size.Height properties represent the width and height of the client area of the control. You can use this property to obtain the size of the client area of the control for tasks such as drawing on the surface of the control.
          /// @remarks For more information about drawing on controls, see Rendering a Windows Forms Control.
          Property<System::Drawing::Size> ClientSize {
            pcf_get {return this->clientSize;},
            pcf_set {this->SetClientSize(value);}
          };
          
          /// @brief Gets the name of the company or creator of the application containing the control.
          /// @return The company name or creator of the application containing the control.
          /// @remarks The CompanyName property is a read-only property. To change the value of this property, set the company member value in your Control constructor.
          Property<string, ReadOnly> CompanyName {
            pcf_get {return this->companyName;}
          };
          
          /// @brief Gets a value indicating whether the control, or one of its child controls, currently has the input focus.
          /// @return true if the control or one of its child controls currently has the input focus; otherwise, false.
          /// @remarks You can use this property to determine whether a control or any of the controls contained within it has the input focus. To determine whether the control has focus, regardless of whether any of its child controls have focus, use the Focused property. To give a control the input focus, use the Focus or Select methods.
          Property<bool, ReadOnly> ContainsFocus {
            pcf_get {return this->containsFocus;}
          };
          
          Property<ControlCollection&> Controls {
            pcf_get->ControlCollection& {return this->controls;},
            pcf_set {this->controls = value;}
          };
          
          Property<System::Windows::FormsD::Cursor> Cursor {
            pcf_get {return this->GetCursor();},
            pcf_set {this->SetCursor(value);}
          };
          
          Property<System::Windows::FormsD::Cursor, ReadOnly> DefaultCursor {
            pcf_get {return this->GetDefaultCursor();}
          };
          
          Property<System::Drawing::Size, ReadOnly> DefaultSize {
            pcf_get {return this->GetDefaultSize();}
          };
          
          /// @brief Gets the name of the company or creator of the application containing the control.
          Property<DockStyle> Dock {
            pcf_get {return this->GetDock();},
            pcf_set {this->SetDock(value);}
          };
          
          Property<bool> Enabled {
            pcf_get {return this->GetEnabled();},
            pcf_set {this->SetEnabled(value);}
          };
          
          Property<bool, ReadOnly> Focused {
            pcf_get {return this->GetFocused();}
          };
          
          Property<const System::Drawing::Font&> Font {
            pcf_get->const System::Drawing::Font& {return this->GetFont();},
            pcf_set {this->SetFont(value);}
          };
          
          Property<System::Drawing::Color> ForeColor {
            pcf_get {return this->foreColor;},
            pcf_set {this->SetForeColor(value);}
          };

          Property<const IWidget&, ReadOnly> Handle {
            pcf_get->const IWidget& {return GetHandle();}
          };

          Property<int32> Height {
            pcf_get {return this->size.Height();},
            pcf_set {this->Size = System::Drawing::Size(this->size.Width(), value);}
          };
          
          Property<int32> Left {
            pcf_get {return this->location.X();},
            pcf_set {this->Location = System::Drawing::Point(value, this->location.Y());}
          };
          
          Property<System::Drawing::Point> Location {
            pcf_get {return this->location;},
            pcf_set {this->SetLocation(value);}
          };
          
          Property<const string&> Name {
            pcf_get->const string& {return this->GetName();},
            pcf_set {this->SetName(value);}
          };
          
          Property<const Control&> Parent {
            pcf_get->const Control& {return this->GetParent();},
            pcf_set {this->SetParent(value);}
          };
          
          Property<bool, ReadOnly> HasParent {
            pcf_get {return this->parent != null;}
          };
          
          Property<int32, ReadOnly> Right {
            pcf_get {return this->Location().X() + this->Size().Width();;}
          };
          
          Property<System::Drawing::Size> Size {
            pcf_get {return this->size;},
            pcf_set {this->SetSize(value);}
          };
          
          Property<string> Text {
            pcf_get {return this->GetText();},
            pcf_set {this->SetText(value);}
          };
          
          Property<int32> Top {
            pcf_get {return this->location.Y();},
            pcf_set {this->Location = System::Drawing::Point(this->location.X(), value);}
          };
          
          Property<bool> Visible {
            pcf_get {return this->GetVisible();},
            pcf_set {this->SetVisible(value);}
          };
          
          Property<int32> Width {
            pcf_get {return this->size.Width();},
            pcf_set {this->Size = System::Drawing::Size(value, this->size.Height());}
          };
          
          Property<bool> UseWaitCursor {
            pcf_get {return this->useWaitCursor;},
            pcf_set {this->useWaitCursor = value;}
          };

          System::Drawing::Graphics CreateGraphics() const {
            return this->graphics;
          }
          
          virtual DragDropEffects DoDragDrop(const Reference<object>& data, DragDropEffects allowedEffects);
          
          virtual void Hide() {
            Visible(false);
          }

          virtual void Invalidate();

          virtual void Invoke(const MethodInvoker& method);

          virtual bool Focus();
          
          System::Drawing::Point PointToClient(const System::Drawing::Point point) const;
          
          System::Drawing::Point PointToScreen(const System::Drawing::Point point) const;
         
          void PerformLayout();
          
          void ResumeLayout() {this->ResumeLayout(true);}

          void ResumeLayout(bool performLayout) {
            if (--this->suspendLayout < 0)
              this->suspendLayout = 0;
            
            if (this->suspendLayout == 0 || performLayout)
              PerformLayout();
          }
          
          virtual void Show() {this->Visible(true);}

          virtual void SuspendLayout() {this->suspendLayout++;}

          /// @brief This event is not relevant for this class.
          /// @remarks This event is not relevant for this class.
          System::EventHandler AutoSizeChanged;

          /// @brief Occurs when the value of the Control::SetBackColor property changes.
          /// @remarks This event is raised if the BackColor property is changed by either a programmatic modification or user interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @remarks The following code example is an event handler that is executed when the Text property value changes. The Control class has several methods with the name pattern PropertyName Changed that are raised when the corresponding PropertyName value changes (PropertyName represents the name of the corresponding property).
          /// @remarks The following code example changes the ForeColor of a TextBox displaying currency data. The example converts the text to a decimal number and changes the ForeColor to Color::Red if the number is negative and to Color::Black if the number is positive. This example requires that you have a Form that contains a TextBox.
          /// @code
          /// void CurrencyTextBoxTextChanged(const object& sender, const EventArgs& e) {
          ///   try {
          ///     // Convert the text to a Double and determine if it is a negative number.
          ///     if (Double::Parse(currencyTextBox->Text()) < 0) {
          ///       // If the number is negative, display it in Red.
          ///       currencyTextBox->ForeColor(Color::Red());
          ///     } else {
          ///       // If the number is not negative, display it in Black.
          ///       currencyTextBox->ForeColor(Color::Black());
          ///     }
          ///   } catch(...) {
          ///     // If there is an error, display the text using the system colors.
          ///     currencyTextBox->ForeColor(SystemColors::ControlText());
          ///   }
          /// }
          /// @endcode
          System::EventHandler BackColorChanged;

          /// @brief Occurs when the value of the Control::SetBackgroundImage property changes.
          /// @remarks This event is raised if the BackgroundImage property is changed by either a programmatic modification or user interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @remarks The following code example is an event handler that is executed when the Text property value changes. The Control class has several methods with the name pattern PropertyName Changed that are raised when the corresponding PropertyName value changes (PropertyName represents the name of the corresponding property).
          /// @remarks The following code example changes the ForeColor of a TextBox displaying currency data. The example converts the text to a decimal number and changes the ForeColor to Color::Red if the number is negative and to Color::Black if the number is positive. This example requires that you have a Form that contains a TextBox.
          /// @code
          /// void CurrencyTextBoxTextChanged(const object& sender, const EventArgs& e) {
          ///   try {
          ///     // Convert the text to a Double and determine if it is a negative number.
          ///     if (Double::Parse(currencyTextBox->Text()) < 0) {
          ///       // If the number is negative, display it in Red.
          ///       currencyTextBox->ForeColor(Color::Red());
          ///     } else {
          ///       // If the number is not negative, display it in Black.
          ///       currencyTextBox->ForeColor(Color::Black());
          ///     }
          ///   } catch {
          ///     // If there is an error, display the text using the system colors.
          ///     currencyTextBox->ForeColor(SystemColors::ControlText());
          ///   }
          /// }
          /// @endcode
          System::EventHandler BackgroundImageChanged;

          /// @brief Occurs when the value of the Control::SetBackgroundImageLayout property changes.
          /// @remarks This event is raised if the BackgroundImageLayout property is changed by either a programmatic modification or user interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @remarks The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the BackgroundImageLayoutChanged event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.
          /// @remarks To run the example code, paste it into a project that contains an instance of a type that inherits from Control, such as a Button or ComboBox. Then name the instance Control1 and ensure that the event handler is associated with the BackgroundImageLayoutChanged event.
          /// @code
          /// void Control1BackgroundImageLayoutChanged(const object& sender, const EventArgs& e) {
          ///   MessageBox::Show("You are in the Control::BackgroundImageLayoutChanged event.");
          /// }
          /// @endcode
          System::EventHandler BackgroundImageLayoutChanged;

          /*
          /// @brief Occurs when the value of the System::Windows::Forms::SetBindingContext property changes.
          /// @remarks To add a new BindingContext to the Control through the BindingContext property, see the BindingContext constructor.
          /// @remarks This event is raised if the BindingContext property is changed is changed by either a programmatic modification or user interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @remarks The following code example adds an EventHandler delegate to the BindingContextChanged event of a TextBox control.
          /// @code
          /// void AddEventHandler() {
          ///   textBox1.BindingContextChanged += new EventHandler(*this, &Form1::BindingContextChanged);
          /// }
          /// void BindingContextChanged(const object& sender, const EventArgs& e) {
          ///   Console::WriteLine("BindingContext changed");
          /// }
          /// @endcode
          System::EventHandler BindingContextChanged;
           */

          /// @brief Occurs when the value of the Control::SetCausesValidation property changes.
          /// @remarks This event is raised if the CausesValidation property is changed by either a programmatic modification or user interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          System::EventHandler CausesValidationChanged;

          /// @brief Occurs when the focus or keyboard user interface (UI) cues change.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @remarks The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the ChangeUICues event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.
          /// @remarks To run the example code, paste it into a project that contains an instance of a type that inherits from Control, such as a Button or ComboBox. Then name the instance Control1 and ensure that the event handler is associated with the ChangeUICues event.
          /// @code
          /// void Control1ChangeUICues(const bject& sender, const UICuesEventArgs& e) {
          ///   System::Text::StringBuilder messageBoxCS;
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ShowFocus", e.ShowFocus());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ShowKeyboard", e.ShowKeyboard());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ChangeFocus", e.ChangeFocus());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "ChangeKeyboard", e.ChangeKeyboard());
          ///   messageBoxCS.AppendLine();
          ///   messageBoxCS.AppendFormat("{0} = {1}", "Changed", e.Changed());
          ///   messageBoxCS.AppendLine();
          ///   MessageBox::Show(messageBoxCS.ToString(), "ChangeUICues Event");
          /// }
          /// @endcode
          UICuesEventHandler ChangeUICues;

          /// @brief Occurs when the control is clicked.
          /// @remarks The Click event passes an EventArgs to its event handler, so it only indicates that a click has occurred. If you need more specific mouse information (button, number of clicks, wheel rotation, or location), use the MouseClick event. However, the MouseClick event will not be raised if the click is caused by action other than that of the mouse, such as pressing the ENTER key.
          /// @remarks A double-click is determined by the mouse settings of the user's operating system. The user can set the time between clicks of a mouse button that should be considered a double-click rather than two clicks. The Click event is raised every time a control is double-clicked. For example, if you have event handlers for the Click and DoubleClick events of a Form, the Click and DoubleClick events are raised when the form is double-clicked and both methods are called. If a control is double-clicked and that control does not support the DoubleClick event, the Click event might be raised twice.
          /// @remarks You must set the StandardClick value of ControlStyles to true for this event to be raised.
          /// @note The following events are not raised for the TabControl class unless there is at least one TabPage in the TabControl.TabPages collection: Click, DoubleClick, MouseDown, MouseUp, MouseHover, MouseEnter, MouseLeave and MouseMove. If there is at least one TabPage in the collection, and the user interacts with the tab control's header (where the TabPage names appear), the TabControl raises the appropriate event. However, if the user interaction is within the client area of the tab page, the TabPage raises the appropriate event.
          /// @note For more information about handling events, see Handling and Raising Events.
          /// @note <b>Notes to Inheritors</b>
          /// @note Inheriting from a standard Windows Forms control and changing the StandardClick or StandardDoubleClick values of ControlStyles to true can cause unexpected behavior or have no effect at all if the control does not support the Click or DoubleClick events.
          /// @note The following table lists Windows Forms controls and which event (Click or DoubleClick) is raised in response to the mouse action specified.
          /// | Control                                                                                                             | Left Mouse Click | Left Mouse Double-Click | Right Mouse Click | Right Mouse Double-Click | Middle Mouse Click | Middle Mouse Double-Click | XButton1 Mouse Click | XButton1 Mouse Double-Click | XButton2 Mouse Click | XButton2 Mouse Double-Click |
          /// |---------------------------------------------------------------------------------------------------------------------|------------------|-------------------------|-------------------|--------------------------|--------------------|---------------------------|----------------------|-----------------------------|----------------------|-----------------------------|
          /// | MonthCalendar, DateTimepicker, HScrollBar, VScrollBar                                                               | none             | none                    | none              | none                     | none               | none                      | none                 | none                        | none                 | none                        |
          /// | Button, CheckBox, RichTextBox, RadioButton                                                                          | Click            | Click, Click            | none              | none                     | none               | none                      | none                 | none                        | none                 | none                        |
          /// | ListBox, CheckedListBox, ComboBox                                                                                   | Click            | Click, DoubleClick      | none              | none                     | none               | none                      | none                 | none                        | none                 | none                        |
          /// | TextBox, DomainUpDown, NumericUpDown                                                                                | Click            | Click, DoubleClick      | none              | none                     | none               | none                      | none                 | none                        | none                 | none                        |
          /// | * TreeView, * ListView                                                                                              | Click            | Click, DoubleClick      | Click             | Click, DoubleClick       | none               | none                      | none                 | none                        | none                 | none                        |
          /// | ProgressBar, TrackBar                                                                                               | Click            | Click, Click            | Click             | Click, Click             | Click              | Click, Click              | Click                | Click, Click                | Click                | Click, Click                |
          /// | Form, DataGrid, Label, LinkLabel, Panel, GroupBox, PictureBox, Splitter, StatusBar, ToolBar, TabPage, ** TabControl | Click            | Click, DoubleClick      | Click             | Click, DoubleClick       | Click              | Click, DoubleClick        | Click                | Click, DoubleClick          | Click                | Click, DoubleClick          |
          /// * The mouse pointer must be over a child object (TreeNode or ListViewItem).
          /// ** The TabControl must have at least one TabPage in its TabPages collection.
          /// @note The following code example shows the Click event in an event handler.
          /// @code
          /// // This example uses the Parent property and the Find method of Control to set
          /// // properties on the parent control of a Button and its Form. The example assumes
          /// // that a Button control named button1 is located within a GroupBox control. The
          /// // example also assumes that the Click event of the Button control is connected to
          /// // the event handler method defined in the example.
          /// void Button1Click(const object& sender, const System::EventArgs& e) {
          ///   // Get the control the Button control is located in. In this case a GroupBox.
          ///   Control& control = button1->Parent();
          ///   // Set the text and backcolor of the parent control.
          ///   control.Text("My Groupbox");
          ///   control.BackColor(Color::Blue);
          ///   // Get the form that the Button control is contained within.
          ///   Form& myForm = button1->FindForm();
          ///   // Set the text and color of the form containing the Button.
          ///   myForm.Text("The Form of My Control");
          ///   myForm.SetBackColo(Color.Red);
          /// }
          /// @endcode
          System::EventHandler Click;

          /// @brief Occurs when the value of the Control::SetClientSize property changes.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @remarks The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the ClientSizeChanged event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.
          /// @remarks To run the example code, paste it into a project that contains an instance of a type that inherits from Control, such as a Button or ComboBox. Then name the instance Control1 and ensure that the event handler is associated with the ClientSizeChanged event.
          /// @code
          /// void Control1ClientSizeChanged(const Object& sender, const EventArgs& e) {
          ///   MessageBox::Show("You are in the Control::ClientSizeChanged event.");
          /// }
          /// @endcode
          System::EventHandler ClientSizeChanged;

          /// @brief Occurs when the value of the Control::SetContextMenu property changes.
          /// @remarks This event is raised if the ContextMenu property is changed by either a programmatic modification or user interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @remarks The following code example displays a message when a change occurs to the shortcut menu.
          /// @code
          /// void AddContextMenuChangedHandler() {
          ///   myTextBox->ContextMenuChanged += new EventHandler(*this, &Form1::TextBoxContextMenuChanged);
          /// }
          /// void TextBoxContextMenuChanged(const object& sender, const EventArgs& e) {
          ///   MessageBox::Show("Shortcut menu of TextBox is changed.");
          /// }
          /// @endcode
          System::EventHandler ContextMenuChanged;

          /// @brief Occurs when the value of the Control::SetContextMenuStrip property changes.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @remarks The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the ContextMenuStripChanged event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.
          /// @remarks To run the example code, paste it into a project that contains an instance of a type that inherits from Control, such as a Button or ComboBox. Then name the instance Control1 and ensure that the event handler is associated with the ContextMenuStripChanged event.
          /// @code
          /// void Control1ContextMenuStripChanged(const Object& sender, const EventArgs& e) {
          ///   MessageBox::Show("You are in the Control::ContextMenuStripChanged event.");
          /// }
          /// @endcode
          System::EventHandler ContextMenuStripChanged;

          /// @brief Occurs when a new control is added to the System::Windows::Forms::Control::ControlCollection.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @remarks The following code example demonstrates the use of the ControlAdded and ControlRemoved events. The example requires that two Button controls are added to the form and connected to the addControl_Click and removeControl_Click event handling methods.
          /// @code
          /// // This example demonstrates the use of the ControlAdded and
          /// // ControlRemoved events. This example assumes that two Button controls
          /// // are added to the form and connected to the AddControlClick and
          /// // RemoveControlClick event-handler methods.
          /// void Form1Load(const object& sender, const System::EventArgs& e) {
          ///   // Connect the ControlRemoved and ControlAdded event handlers
          ///   // to the event-handler methods.
          ///   // ControlRemoved and ControlAdded are not available at design time.
          ///   ControlRemoved += new System::Windows::Forms::ControlEventHandler(*this, &Form1::ControlRemoved);
          ///   ControlAdded += new System::Windows::Forms::ControlEventHandler(*this, &Form1::ControlAdded);
          /// }
          /// void ControlAdded(const object& sender, const System::Windows::Forms::ControlEventArgs& e) {
          ///   MessageBox::Show("The control named " + e.Control()->Name() + " has been added to the form.");
          /// }
          /// void ControlRemoved(const object& sender, const System::Windows::Forms::ControlEventArgs& e) {
          ///   MessageBox::Show("The control named " + e.Control()->Name() + " has been removed from the form.");
          /// }
          /// // Click event handler for a Button control. Adds a TextBox to the form.
          /// void AddControlClick(const object& sender, const System::EventArgs& e) {
          ///   // Create a new TextBox control and add it to the form.
          ///   UniquePointer<TextBox> textBox1 = new TextBox();
          ///   textBox1->Size(Size(100, 10));
          ///   textBox1->Location(Point(10, 10));
          ///   // Name the control in order to remove it later. The name must be specified
          ///   // if a control is added at run time.
          ///   textBox1->Name("textBox1");
          ///   // Add the control to the form's control collection.
          ///   GetControls().Add(*textBox1);
          /// }
          /// // Click event handler for a Button control.
          /// // Removes the previously added TextBox from the form.
          /// void RemoveControlClick(const object& sender, const System::EventArgs& e) {
          ///   // Loop through all controls in the form's control collection.
          ///   for (Control tempCtrl : GetControls()) {
          ///     // Determine whether the control is textBox1,
          ///     // and if it is, remove it.
          ///     if (tempCtrl.Name() == "textBox1") {
          ///       GetControls().Remove(tempCtrl);
          ///     }
          ///   }
          /// }
          /// @endcode
          ControlEventHandler ControlAdded;

          /// @brief Occurs when a new control is removed from the System::Windows::Forms::Control::ControlCollection.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @remarks The following code example demonstrates the use of the ControlAdded and ControlRemoved events. The example requires that two Button controls are added to the form and connected to the addControl_Click and removeControl_Click event handling methods.
          /// @code
          /// // This example demonstrates the use of the ControlAdded and
          /// // ControlRemoved events. This example assumes that two Button controls
          /// // are added to the form and connected to the AddControlClick and
          /// // RemoveControlClick event-handler methods.
          /// void Form1Load(const object& sender, const System::EventArgs& e) {
          ///   // Connect the ControlRemoved and ControlAdded event handlers
          ///   // to the event-handler methods.
          ///   // ControlRemoved and ControlAdded are not available at design time.
          ///   ControlRemoved += new System::Windows::Forms::ControlEventHandler(*this, &Form1::ControlRemoved);
          ///   ControlAdded += new System::Windows::Forms::ControlEventHandler(*this, &Form1::ControlAdded);
          /// }
          /// void ControlAdded(const object& sender, const System::Windows::Forms::ControlEventArgs& e) {
          ///   MessageBox::Show("The control named " + e.Control()->Name() + " has been added to the form.");
          /// }
          /// void ControlRemoved(const object& sender, const System::Windows::Forms::ControlEventArgs& e) {
          ///   MessageBox::Show("The control named " + e.Control()->Name() + " has been removed from the form.");
          /// }
          /// // Click event handler for a Button control. Adds a TextBox to the form.
          /// void AddControlClick(const object& sender, const System::EventArgs& e) {
          ///   // Create a new TextBox control and add it to the form.
          ///   UniquePointer<TextBox> textBox1 = new TextBox();
          ///   textBox1->Size(Size(100, 10));
          ///   textBox1->Location(Point(10, 10));
          ///   // Name the control in order to remove it later. The name must be specified
          ///   // if a control is added at run time.
          ///   textBox1->Name("textBox1");
          ///   // Add the control to the form's control collection.
          ///   GetControls().Add(*textBox1);
          /// }
          /// // Click event handler for a Button control.
          /// // Removes the previously added TextBox from the form.
          /// void RemoveControlClick(const object& sender, const System::EventArgs& e) {
          ///   // Loop through all controls in the form's control collection.
          ///   for (Control tempCtrl : GetControls()) {
          ///     // Determine whether the control is textBox1,
          ///     // and if it is, remove it.
          ///     if (tempCtrl.Name() == "textBox1") {
          ///       GetControls().Remove(tempCtrl);
          ///     }
          ///   }
          /// }
          /// @endcode
          ControlEventHandler ControlRemoved;

          /// @brief Occurs when the value of the Control::SetCursor property changes.
          /// @remarks This event is raised if the Cursor property is changed by either a programmatic modification or user interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @remarks The following code example demonstrates changing the mouse cursor using the Control.Cursor property, the Cursor class, and the Cursors class. The example creates a form that contains a ComboBox control, a Panel control, and a ListView control. The ComboBox contains all cursors provided by the Cursors class. When the user selects a mouse cursor in the ComboBox, the Control.Cursor property is set to the selected cursor, which updates the cursor for the Panel. The ListView is updated every time the Control.CursorChanged event occurs.
          /// @code
          /// #include <Pcf/Pcf>
          ///
          /// using namespace System;
          /// using namespace System::Drawing;
          /// using namespace System::Windows::Forms;
          ///
          /// namespace MCursor {
          ///   class Form1 : System::Windows::Forms::Form {
          ///   private:
          ///     UniquePointer<System::Windows::Forms::ComboBox> cursorSelectionComboBox;
          ///     UniquePointer<System::Windows::Forms::Panel> testPanel;
          ///     UniquePointer<System::Windows::Forms::Label> label1;
          ///     UniquePointer<System::Windows::Forms::Label> label2;
          ///     UniquePointer<System::Windows::Forms::ListView> cursorEventViewer;
          ///     UniquePointer<System::Windows::Forms::Label> label3;
          ///   public:
          ///     static void Main() {
          ///       Application::Run(Form1());
          ///     }
          ///
          ///     Form1() {
          ///       cursorSelectionComboBox = new System::Windows::Forms::ComboBox();
          ///       testPanel = new System::Windows::Forms::Panel();
          ///       label1 = new System::Windows::Forms::Label();
          ///       label2 = new System::Windows::Forms::Label();
          ///       cursorEventViewer = new System::Windows::Forms::ListView();
          ///       label3 = new System::Windows::Forms::Label();
          ///       // Select Cursor Label
          ///       label2->Location(System::Drawing::Point(24, 16));
          ///       label2->Size(System::Drawing::Size(80, 16));
          ///       label2->Text("Select cursor:");
          ///       // Cursor Testing Panel Label
          ///       label1->Location(System::Drawing::Point(24, 80));
          ///       label1->Size(System::Drawing::Size(144, 23));
          ///       label1->Text("Cursor testing panel:");
          ///       // Cursor Changed Events Label
          ///       label3->SetLocatio(System::Drawing::Point(184, 16));
          ///       label3->Size(System::Drawing::Size(128, 16));
          ///       label3->Text("Cursor changed events:");
          ///       // Cursor Selection ComboBox
          ///       cursorSelectionComboBox->Location(System::Drawing::Point(24, 40));
          ///       cursorSelectionComboBox->Size(System::Drawing::Size(152, 21));
          ///       cursorSelectionComboBox->SetTabIndex(0);
          ///       cursorSelectionComboBox->SelectedIndexChanged += System::EventHandler(*this, &CursorSelectionComboBoxSelectedIndexChanged);
          ///       // Cursor Test Panel
          ///       testPanel->BackColor(System::Drawing::SystemColors::ControlDark());
          ///       testPanel->Location(System::Drawing::Point(24, 104));
          ///       testPanel->SetSize = new System::Drawing::Size(152, 160));
          ///       testPanel->CursorChanged += System::EventHandler(*this, &TestPanelCursorChanged);
          ///       // Cursor Event ListView
          ///       cursorEventViewer->Location(System::Drawing::Point(184, 40));
          ///       cursorEventViewer->Size(System::Drawing::Size(256, 224));
          ///       cursorEventViewer->SetTabIndex(4);
          ///       cursorEventViewer->SetView(System::Windows::Forms::View::List);
          ///       // Set up how the form should be displayed and add the controls to the form.
          ///       SetClientSize(System::Drawing::Size(456, 286);
          ///       GetControls().AddRange(Array<System::Windows::Forms::Control> {
          ///         *label3, *cursorEventViewer,
          ///         *label2, *label1,
          ///         *testPanel, *cursorSelectionComboBox});
          ///       Text("Cursors Example");
          ///       // Add all the cursor types to the combobox.
          ///       for (Cursor cursor : CursorList()) {
          ///         cursorSelectionComboBox.GetItems().Add(cursor);
          ///       }
          ///     }
          ///     Array<Cursor> CursorList() {
          ///       // Make an array of all the types of cursors in Windows Forms::
          ///       return {
          ///         Cursors::AppStarting(), Cursors::Arrow(), Cursors::Cross(),
          ///         Cursors::Default(), Cursors::Hand(), Cursors::Help(),
          ///         Cursors::HSplit(), Cursors::IBeam(), Cursors::No(),
          ///         Cursors::NoMove2D(), Cursors::NoMoveHoriz(), Cursors::NoMoveVert(),
          ///         Cursors::PanEast(), Cursors::PanNE(), Cursors::PanNorth(),
          ///         Cursors::PanNW(), Cursors::PanSE(), Cursors::PanSouth(),
          ///         Cursors::PanSW(), Cursors::PanWest(), Cursors::SizeAll(),
          ///         Cursors::SizeNESW(), Cursors::SizeNS(), Cursors::SizeNWSE(),
          ///         Cursors::SizeWE(), Cursors::UpArrow(), Cursors::VSplit(), Cursors::WaitCursor()};
          ///     }
          ///     void CursorSelectionComboBoxSelectedIndexChanged(const object& sender, const System::EventArgs& e) {
          ///       // Set the cursor in the test panel to be the selected cursor style.
          ///       testPanel.Cursor = (Cursor)cursorSelectionComboBox.SelectedItem();
          ///     }
          ///     void TestPanelCursorChanged(const object& sender, const System::EventArgs& e) {
          ///       // Build up a string containing the type of object sending the event, and the event.
          ///       string cursorEvent = string.Format("[{0}]: {1}", sender.GetType().ToString(), "Cursor changed");
          ///       // Record this event in the list view.
          ///       cursorEventViewer.GetItems().Add(cursorEvent);
          ///     }
          ///   };
          /// }
          ///
          /// pcf_startup (MCursor::Form1())
          /// @endcode
          System::EventHandler CursorChanged;

          /// @brief Occurs when the value of the Control::SetDock property changes.
          /// @remarks This event is raised if the Dock property is changed by either a programmatic modification or user interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @remarks The following code example is an event handler that is executed when the Text property value changes. The Control class has several methods with the name pattern PropertyName Changed that are raised when the corresponding PropertyName value changes(PropertyName represents the name of the corresponding property).
          /// @remarks The following code example changes the ForeColor of a TextBox displaying currency data. The example converts the text to a decimal number and changes the ForeColor to Color.Red if the number is negative and to Color.Black if the number is positive. This example requires that you have a Form that contains a TextBox.
          /// @code
          /// void CurrencyTextBoxTextChanged(const object& sender, const EventArgs& e) {
          ///   try {
          ///     // Convert the text to a Double and determine if it is a negative number.
          ///     if (Double::Parse(currencyTextBox->Text()) < 0) {
          ///       // If the number is negative, display it in Red.
          ///       currencyTextBox->ForeColor(Color::Red());
          ///     } else {
          ///       // If the number is not negative, display it in Black.
          ///       currencyTextBox->ForeColor(Color::Black());
          ///     }
          ///   } catch {
          ///     // If there is an error, display the text using the system colors.
          ///     currencyTextBox->ForeColor(SystemColors::ControlText());
          ///   }
          /// }
          /// @endcode
          System::EventHandler DockChanged;

          /// @brief Occurs when the control is double-clicked.
          /// @remarks A double-click is determined by the mouse settings of the user's operating system. The user can set the time between clicks of a mouse button that should be considered a double-click rather than two clicks. The Click event is raised every time a control is double-clicked. For example, if you have event handlers for the Click and DoubleClick events of a Form, the Click and DoubleClick events are raised when the form is double-clicked and both methods are called. If a control is double-clicked and that control does not support the DoubleClick event, the Click event might be raised twice.
          /// @remarks You must set the StandardDoubleClick and StandardClick values of ControlStyles to true for this event to be raised. These values might already be set to true if you are inheriting from existing Windows Forms controls.
          /// @note The following events are not raised for the TabControl class unless there is at least one TabPage in the TabControl.TabPages collection: Click, DoubleClick, MouseDown, MouseUp, MouseHover, MouseEnter, MouseLeave and MouseMove. If there is at least one TabPage in the collection, and the user interacts with the tab control's header (where the TabPage names appear), the TabControl raises the appropriate event. However, if the user interaction is within the client area of the tab page, the TabPage raises the appropriate event.
          /// @note For more information about handling events, see Handling and Raising Events.
          /// @note <b>Notes to Inheritors</b>
          /// @note Inheriting from a standard Windows Forms control and changing the StandardClick or StandardDoubleClick values of ControlStyles to true can cause unexpected behavior or have no effect at all if the control does not support the Click or DoubleClick events.
          /// @note The following table lists Windows Forms controls and which event (Click or DoubleClick) is raised in response to the mouse action specified.
          /// | Control                                                                                                             | Left Mouse Click | Left Mouse Double-Click | Right Mouse Click | Right Mouse Double-Click | Middle Mouse Click | Middle Mouse Double-Click | XButton1 Mouse Click | XButton1 Mouse Double-Click | XButton2 Mouse Click | XButton2 Mouse Double-Click |
          /// |---------------------------------------------------------------------------------------------------------------------|------------------|-------------------------|-------------------|--------------------------|--------------------|---------------------------|----------------------|-----------------------------|----------------------|-----------------------------|
          /// | MonthCalendar, DateTimepicker, HScrollBar, VScrollBar                                                               | none             | none                    | none              | none                     | none               | none                      | none                 | none                        | none                 | none                        |
          /// | Button, CheckBox, RichTextBox, RadioButton                                                                          | Click            | Click, Click            | none              | none                     | none               | none                      | none                 | none                        | none                 | none                        |
          /// | ListBox, CheckedListBox, ComboBox                                                                                   | Click            | Click, DoubleClick      | none              | none                     | none               | none                      | none                 | none                        | none                 | none                        |
          /// | TextBox, DomainUpDown, NumericUpDown                                                                                | Click            | Click, DoubleClick      | none              | none                     | none               | none                      | none                 | none                        | none                 | none                        |
          /// | * TreeView, * ListView                                                                                              | Click            | Click, DoubleClick      | Click             | Click, DoubleClick       | none               | none                      | none                 | none                        | none                 | none                        |
          /// | ProgressBar, TrackBar                                                                                               | Click            | Click, Click            | Click             | Click, Click             | Click              | Click, Click              | Click                | Click, Click                | Click                | Click, Click                |
          /// | Form, DataGrid, Label, LinkLabel, Panel, GroupBox, PictureBox, Splitter, StatusBar, ToolBar, TabPage, ** TabControl | Click            | Click, DoubleClick      | Click             | Click, DoubleClick       | Click              | Click, DoubleClick        | Click                | Click, DoubleClick          | Click                | Click, DoubleClick          |
          /// * The mouse pointer must be over a child object (TreeNode or ListViewItem).
          /// ** The TabControl must have at least one TabPage in its TabPages collection.
          /// @note The following code example uses the DoubleClick event of a ListBox to load text files listed in the ListBox into a TextBox control.
          /// @code
          /// // This example uses the DoubleClick event of a ListBox to load text files
          /// // listed in the ListBox into a TextBox control. This example
          /// // assumes that the ListBox, named listBox1, contains a list of valid file
          /// // names with path and that this event handler method
          /// // is connected to the DoublClick event of a ListBox control named listBox1.
          /// // This example requires code access permission to access files.
          /// void listBox1_DoubleClick(const object& sender, const System::EventArgs& e) {
          ///   // Get the name of the file to open from the ListBox.
          ///   String file = listBox1->SelectedItem().ToString();
          ///   try {
          ///     // Determine if the file exists before loading.
          ///     if (System::IO::File::Exists(file)) {
          ///       // Open the file and use a TextReader to read the contents into the TextBox.
          ///       System::IO::FileInfo myFile(listBox1->SelectedItem().ToString());
          ///       UniquePointer<System::IO::TextReader> myData = myFile.OpenText();
          ///       textBox1->Text(myData->ReadToEnd());
          ///       myData->Close();
          ///     }
          ///   } catch(const System::IO::FileNotFoundException&) {
          ///     // Exception is thrown by the OpenText method of the FileInfo class.
          ///     MessageBox.Show("The file you specified does not exist.");
          ///   } catch(const System::IO::IOException&) {
          ///     // Exception is thrown by the ReadToEnd method of the TextReader class.
          ///     MessageBox.Show("There was a problem loading the file into the TextBox. Ensure that the file is a valid text file.");
          ///   }
          /// }
          /// @endcode
          System::EventHandler DoubleClick;

          /// @brief Occurs when a drag-and-drop operation is completed.
          /// @remarks The X and Y properties of the DragEventArgs are in screen coordinates, not client coordinates. The following line of C++ code converts the properties to a client Point.
          /// @verbatim Point clientPoint = targetControl.PointToClient(new Point(de.X, de.Y)); @endverbatim
          /// @note In versions earlier than .NET Framework 2.0, if you put a UserControl with DragEnter and DragDrop events on a Windows Form and drag and drop something onto the UserControl at design time, the DropDrop and DropEnter events are raised. However, when you close and reopen the solution, the DragEnter and DragDrop events are not raised again.
          /// @note For more information about handling events, see Handling and Raising Events.
          /// @note This code excerpt demonstrates using the DragDrop event. See the DoDragDrop method for the complete code example.
          /// @code
          /// void ListDragTarget_DragDrop(const object& sender, const System::Windows::Forms::DragEventArgs& e) {
          ///   // Ensure that the list item index is contained in the data.
          ///   if (e.Data.GetDataPresent(typeof(System::String))) {
          ///     SharedPointer<object> item = e.GetData().GetData<string>().ChangeType<object>();
          ///     // Perform drag-and-drop, depending upon the effect.
          ///     if (e.Effect() == DragDropEffects::Copy || e.Effect() == DragDropEffects::Move) {
          ///       // Insert the item.
          ///       if (indexOfItemUnderMouseToDrop != ListBox::NoMatches())
          ///         ListDragTarget->GetItems().Insert(indexOfItemUnderMouseToDrop, item);
          ///       else
          ///         ListDragTarget->Items.Add(item);
          ///     }
          ///   }
          ///   // Reset the label text.
          ///   DropLocationLabel->Text("None");
          /// }
          /// @endcode
          DragEventHandler DragDrop;

          /// @brief Occurs when an object is dragged into the control's bounds.
          /// @remarks The DragEnter event is raised when the user first drags the mouse cursor over the control during a drag-and-drop operation.
          /// @note In versions earlier than .NET Framework 2.0, if you put a UserControl with DragEnter and DragDrop events on a Windows Form and drag and drop something onto the UserControl at design time, the DropDrop and DropEnter events are raised. However, when you close and reopen the solution, the DragEnter and DragDrop events are not raised again.
          /// @note The following describes how and when events related to drag-and-drop operations are raised.
          /// @note The DoDragDrop method determines the control under the current cursor location. It then checks to see if the control is a valid drop target.
          /// @note If the control is a valid drop target, the GiveFeedback event is raised with the drag-and-drop effect specified. For a list of drag-and-drop effects, see the DragDropEffects enumeration.
          /// @note Changes in the mouse cursor position, keyboard state, and mouse button state are tracked.
          /// * If the user moves out of a window, the DragLeave event is raised.
          /// * If the mouse enters another control, the DragEnter for that control is raised.
          /// * If the mouse moves but stays within the same control, the DragOver event is raised.
          /// @note If there is a change in the keyboard or mouse button state, the QueryContinueDrag event is raised and determines whether to continue the drag, to drop the data, or to cancel the operation based on the value of the Action property of the event's QueryContinueDragEventArgs.
          /// @note  If the value of DragAction is Continue, the DragOver event is raised to continue the operation and the GiveFeedback event is raised with the new effect so appropriate visual feedback can be set. For a list of valid drop effects, see the DragDropEffects enumeration.
          /// @note The DragOver and GiveFeedback events are paired so that as the mouse moves across the drop target, the user is given the most up-to-date feedback on the mouse's position.
          /// * If the value of DragAction is Drop, the drop effect value is returned to the source, so the source application can perform the appropriate operation on the source data; for example, cut the data if the operation was a move.
          /// * If the value of DragAction is Cancel, the DragLeave event is raised.
          /// @note The X and Y properties of the DragEventArgs are in screen coordinates, not client coordinates. The following line of C++ code converts the properties to a client Point.
          /// @verbatim Point clientPoint = targetControl->PointToClient(Point(de.X, de.Y)); @endverbatim
          /// @note For more information about handling events, see Handling and Raising Events.
          /// @note The following code example demonstrates a drag-and-drop operation between two ListBox controls. The example calls the DoDragDrop method when the drag action starts. The drag action starts if the mouse has moved more than SystemInformation.DragSize from the mouse location during the MouseDown event. The IndexFromPoint method is used to determine the index of the item to drag during the MouseDown event.
          /// @note The example also demonstrates using custom cursors for the drag-and-drop operation. The example requires that two cursor files, 3dwarro.cur and 3dwno.cur, exist in the application directory, for the custom drag and no-drop cursors, respectively. The custom cursors will be used if the UseCustomCursorsCheck CheckBox is checked. The custom cursors are set in the GiveFeedback event handler.
          /// @note The keyboard state is evaluated in the DragOver event handler for the right ListBox, to determine what the drag operation will be based on state of the SHIFT, CTRL, ALT, or CTRL+ALT keys. The location in the ListBox where the drop would occur is also determined during the DragOver event. If the data to drop is not a String, then the DragEventArgs.Effect is set to None in DragDropEffects. Finally, the status of the drop is displayed in the DropLocationLabel Label.
          /// @note The data to drop for the right ListBox is determined in the DragDrop event handler and the String value is added at the appropriate place in the ListBox. If the drag operation moves outside the bounds of the form, then the drag-and-drop operation is canceled in the QueryContinueDrag event handler.
          /// @note This code excerpt demonstrates using the DragEnter event. See the DoDragDrop method for the complete code example.
          /// @code
          /// void ListDragTargetDragEnter(const object& sender, const System::Windows::Forms::DragEventArgs& e) {
          ///   // Reset the label text.
          ///   DropLocationLabel->Text("None");
          /// }
          /// @endcode
          DragEventHandler DragEnter;

          /// @brief Occurs when an object is dragged out of the control's bounds.
          /// @remarks The DragLeave event is raised when the user drags the cursor out of the control or the user cancels the current drag-and-drop operation.
          /// @remarks The following describes how and when events related to drag-and-drop operations are raised.
          /// @remarks The DoDragDrop method determines the control under the current cursor location. It then checks to see if the control is a valid drop target.
          /// @remarks If the control is a valid drop target, the GiveFeedback event is raised with the drag-and-drop effect specified. For a list of drag-and-drop effects, see the DragDropEffects enumeration.
          /// @remarks Changes in the mouse cursor position, keyboard state, and mouse button state are tracked.
          /// * If the user moves out of a window, the DragLeave event is raised.
          /// * If the mouse enters another control, the DragEnter for that control is raised.
          /// * If the mouse moves but stays within the same control, the DragOver event is raised.
          /// * If there is a change in the keyboard or mouse button state, the QueryContinueDrag event is raised and determines whether to continue the drag, to drop the data, or to cancel the operation based on the value of the Action property of the event's QueryContinueDragEventArgs.
          /// * If the value of DragAction is Continue, the DragOver event is raised to continue the operation and the GiveFeedback event is raised with the new effect so appropriate visual feedback can be set. For a list of valid drop effects, see the DragDropEffects enumeration.
          /// @note The DragOver and GiveFeedback events are paired so that as the mouse moves across the drop target, the user is given the most up-to-date feedback on the mouse's position.
          /// * If the value of DragAction is Drop, the drop effect value is returned to the source, so the source application can perform the appropriate operation on the source data; for example, cut the data if the operation was a move.
          /// * If the value of DragAction is Cancel, the DragLeave event is raised.
          /// @note For more information about handling events, see Handling and Raising Events.
          /// @note The following code example demonstrates a drag-and-drop operation between two ListBox controls. The example calls the DoDragDrop method when the drag action starts. The drag action starts if the mouse has moved more than SystemInformation.DragSize from the mouse location during the MouseDown event. The IndexFromPoint method is used to determine the index of the item to drag during the MouseDown event.
          /// @note The example also demonstrates using custom cursors for the drag-and-drop operation. The example requires that two cursor files, 3dwarro.cur and 3dwno.cur, exist in the application directory, for the custom drag and no-drop cursors, respectively. The custom cursors will be used if the UseCustomCursorsCheck CheckBox is checked. The custom cursors are set in the GiveFeedback event handler.
          /// @note The keyboard state is evaluated in the DragOver event handler for the right ListBox, to determine what the drag operation will be based on state of the SHIFT, CTRL, ALT, or CTRL+ALT keys. The location in the ListBox where the drop would occur is also determined during the DragOver event. If the data to drop is not a String, then the DragEventArgs.Effect is set to None in DragDropEffects. Finally, the status of the drop is displayed in the DropLocationLabel Label.
          /// @note The data to drop for the right ListBox is determined in the DragDrop event handler and the String value is added at the appropriate place in the ListBox. If the drag operation moves outside the bounds of the form, then the drag-and-drop operation is canceled in the QueryContinueDrag event handler.
          /// @note This code excerpt demonstrates using the DragLeave event. See the DoDragDrop method for the complete code example.
          /// @code
          /// void ListDragTargetDragLeave(const object& sender, const System::EventArgs& e) {
          ///   // Reset the label text.
          ///   DropLocationLabel->Text("None");
          /// }
          /// @endcode
          System::EventHandler DragLeave;

          /// @brief Occurs when an object is dragged over the control's bounds.
          /// @remarks The DragOver event is raised when the mouse cursor moves within the bounds of the control during a drag-and-drop operation.
          /// @remarks The following describes how and when events related to drag-and-drop operations are raised.
          /// @remarks The DoDragDrop method determines the control under the current cursor location. It then checks to see if the control is a valid drop target.
          /// @remarks If the control is a valid drop target, the GiveFeedback event is raised with the drag-and-drop effect specified. For a list of drag-and-drop effects, see the DragDropEffects enumeration.
          /// @remarks Changes in the mouse cursor position, keyboard state, and mouse button state are tracked.
          /// * If the user moves out of a window, the DragLeave event is raised.
          /// * If the mouse enters another control, the DragEnter for that control is raised.
          /// * If the mouse moves but stays within the same control, the DragOver event is raised.
          /// * If there is a change in the keyboard or mouse button state, the QueryContinueDrag event is raised and determines whether to continue the drag, to drop the data, or to cancel the operation based on the value of the Action property of the event's QueryContinueDragEventArgs.
          /// * If the value of DragAction value is Continue, the DragOver event is raised to continue the operation and the GiveFeedback event is raised with the new effect so appropriate visual feedback can be set. For a list of valid drop effects, see the DragDropEffects enumeration.
          /// @note The DragOver and GiveFeedback events are paired so that as the mouse moves across the drop target, the user is given the most up-to-date feedback on the mouse's position.
          /// * If the value of DragAction is Drop, the drop effect value is returned to the source, so the source application can perform the appropriate operation on the source data; for example, cut the data if the operation was a move.
          /// * If the value of DragAction is Cancel, the DragLeave event is raised.
          /// @note The X and Y properties of the DragEventArgs are in screen coordinates, not client coordinates. The following line of C++ code converts the properties to a client Point:
          /// @note Point clientPoint = targetControl.PointToClient(new Point(de.X, de.Y));
          /// @note For more information about handling events, see Handling and Raising Events.
          /// @note The following code example demonstrates a drag-and-drop operation between two ListBox controls. The example calls the DoDragDrop method when the drag action starts. The drag action starts if the mouse has moved more than SystemInformation.DragSize from the mouse location during the MouseDown event. The IndexFromPoint method is used to determine the index of the item to drag during the MouseDown event.
          /// @note The example also demonstrates using custom cursors for the drag-and-drop operation. The example requires that two cursor files, 3dwarro.cur and 3dwno.cur, exist in the application directory, for the custom drag and no-drop cursors, respectively. The custom cursors will be used if the UseCustomCursorsCheck CheckBox is checked. The custom cursors are set in the GiveFeedback event handler.
          /// @note The keyboard state is evaluated in the DragOver event handler for the right ListBox, to determine what the drag operation will be based on state of the SHIFT, CTRL, ALT, or CTRL+ALT keys. The location in the ListBox where the drop would occur is also determined during the DragOver event. If the data to drop is not a String, then the DragEventArgs.Effect is set to None in DragDropEffects. Finally, the status of the drop is displayed in the DropLocationLabel Label.
          /// @note The data to drop for the right ListBox is determined in the DragDrop event handler and the String value is added at the appropriate place in the ListBox. If the drag operation moves outside the bounds of the form, then the drag-and-drop operation is canceled in the QueryContinueDrag event handler.
          /// @note This code excerpt demonstrates using the DragOver event. See the DoDragDrop method for the complete code example.
          /// @code
          /// void ListDragTargetDragOver(const object& sender, const System::Windows::Forms::DragEventArgs& e) {
          ///   // Determine whether string data exists in the drop data. If not, then
          ///   // the drop effect reflects that the drop cannot occur.
          ///   if (!e.GetData().GetDataPresent<System::String>())) {
          ///     e.Effect(DragDropEffects::None);
          ///     DropLocationLabel->Text("None - no string data.");
          ///     return;
          ///   }
          ///   // Set the effect based upon the KeyState.
          ///   if ((e.KeyState() & (8+32)) == (8+32) && (e.AllowedEffect() & DragDropEffects::Link) == DragDropEffects::Link) {
          ///     // KeyState 8 + 32 = CTL + ALT
          ///     // Link drag-and-drop effect.
          ///     e.Effect(DragDropEffects::Link);
          ///   } else if ((e.KeyState() & 32) == 32 && (e.AllowedEffect() & DragDropEffects::Link) == DragDropEffects::Link) {
          ///     // ALT KeyState for link.
          ///     e.Effect(DragDropEffects::Link);
          ///   } else if ((e.KeyState() & 4) == 4 && (e.AllowedEffect() & DragDropEffects::Move) == DragDropEffects::Move) {
          ///     // SHIFT KeyState for move.
          ///     e.Effect(DragDropEffects::Move);
          ///   } else if ((e.KeyState() & 8) == 8 && (e.AllowedEffect() & DragDropEffects::Copy) == DragDropEffects::Copy) {
          ///     // CTL KeyState for copy.
          ///     e.Effect(DragDropEffects::Copy);
          ///   } else if ((e.AllowedEffect() & DragDropEffects::Move) == DragDropEffects.Move) {
          ///     // By default, the drop action should be move, if allowed.
          ///     e.Effect(DragDropEffects::Move);
          ///   } else
          ///     e.Effect(DragDropEffects::None);
          ///   // Get the index of the item the mouse is below.
          ///   // The mouse locations are relative to the screen, so they must be
          ///   // converted to client coordinates.
          ///   indexOfItemUnderMouseToDrop = ListDragTarget->GetIndexFromPoint(ListDragTarget->PointToClient(Point(e.X, e.Y)));
          ///   // Updates the label text.
          ///   if (indexOfItemUnderMouseToDrop != ListBox->NoMatches()){
          ///     DropLocationLabel->Text("Drops before item #" + (indexOfItemUnderMouseToDrop + 1));
          ///   } else
          ///     DropLocationLabel->Text("Drops at the end.");
          /// }
          /// @endcode
          DragEventHandler DragOver;

          /// @brief Occurs when the Control.Enabled property value has changed.
          /// @remarks This event is raised if the Enabled property is changed by either a programmatic modification or user interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @remarks The following code example uses two RadioButton controls to demonstrate the EnabledChanged event. Clicking one button changes the value of the Enabled property of the other button to false and displays a MessageBox.
          /// @code
          /// #include <Pcf/Pcf>
          ///
          /// using namespace System;
          /// using namespace System::Collections::Generic;
          /// using namespace System::ComponentModel;
          /// using namespace System::Data;
          /// using namespace System::Drawing;
          /// using namespace System::Text;
          /// using namespace System::Windows::Forms;
          ///
          /// class Form1 : Form {
          /// private:
          ///   UniquePointer<RadioButton> radioButton1;
          ///   UniquePointer<RadioButton> radioButton2;
          ///   public:
          ///     Form1() {
          ///       InitializeComponent();
          ///     }
          /// private:
          ///   static void Main() {
          ///     Application::EnableVisualStyles();
          ///     Application::SetCompatibleTextRenderingDefault(false);
          ///     Application::Run(Form1());
          ///   }
          ///
          ///   void InitializeComponent() {
          ///     radioButton1 = new System::Windows::Forms::RadioButton();
          ///     radioButton2 = new System::Windows::Forms::RadioButton();
          ///     SuspendLayout();
          ///     //
          ///     // radioButton1
          ///     //
          ///     radioButton1->AutoSize(true);
          ///     radioButton1->Location(System::Drawing::Point(0, 0));
          ///     radioButton1->Name("radioButton1");
          ///     radioButton1->Size(System::Drawing::Size(62, 17));
          ///     radioButton1->SetTabIndex(0);
          ///     radioButton1->SetTabStop(true);
          ///     radioButton1.Text = "Button1";
          ///     radioButton1.UseVisualStyleBackColor = true;
          ///     radioButton1.EnabledChanged += new System::EventHandler(*this, &Form1::radioButton1_EnabledChanged);
          ///     //
          ///     // radioButton2
          ///     //
          ///     radioButton2->AutoSize(true);
          ///     radioButton2->Location(System::Drawing::Point(0, 39));
          ///     radioButton2->Name("radioButton2");
          ///     radioButton2->Size(System::Drawing::Size(100, 17));
          ///     radioButton2->SetTabIndex(1);
          ///     radioButton2.TabStop = true;
          ///     radioButton2->Text("Disable Button1");
          ///     radioButton2->SetUseVisualStyleBackColor(true);
          ///     radioButton2.CheckedChanged += System::EventHandler(*this, &Form1::radioButton2_CheckedChanged);
          ///     //
          ///     // Form1
          ///     //
          ///     SetClientSize(new System::Drawing::Size(292, 273));
          ///     Controls().Add(*radioButton2);
          ///     Controls().Add(*radioButton1);
          ///     Name("Form1");
          ///     ResumeLayout(false);
          ///     PerformLayout();
          ///   }
          /// public:
          ///   void radioButton2_CheckedChanged(object sender, EventArgs e) {
          ///     radioButton1->Enabled(false);
          ///   }
          ///   void radioButton1_EnabledChanged(object sender, EventArgs e) {
          ///     MessageBox::Show("This button has been disabled.");
          ///   }
          /// };
          ///
          /// pcf_startup (Form1())
          /// @endcode
          System::EventHandler EnabledChanged;

          /// @brief Occurs when the control is entered.
          /// @remarks When you change the focus by using the keyboard (TAB, SHIFT+TAB, and so on), by calling the Select or SelectNextControl methods, or by setting the ContainerControl.ActiveControl property to the current form, focus events occur in the following order:
          /// * Enter
          /// * GotFocus
          /// * Leave
          /// * Validating
          /// * Validated
          /// * LostFocus
          /// When you change the focus by using the mouse or by calling the Focus method, focus events occur in the following order:
          /// * Enter
          /// * GotFocus
          /// * LostFocus
          /// * Leave
          /// * Validating
          /// * Validated
          /// @remarks If the CausesValidation property is set to false, the Validating and Validated events are suppressed.
          /// @note The Enter and Leave events are suppressed by the Form class. The equivalent events in the Form class are the Activated and Deactivate events. The Enter and Leave events are hierarchical and will cascade up and down the parent chain until the appropriate control is reached. For example, assume you have a Form with two GroupBox controls, and each GroupBox control has one TextBox control. When the caret is moved from one TextBox to the other, the Leave event is raised for the TextBox and GroupBox, and the Enter event is raised for the other GroupBox and TextBox.
          /// @warning Do not attempt to set focus from within the Enter, GotFocus, Leave, LostFocus, Validating, or Validated event handlers. Doing so can cause your application or the operating system to stop responding. For more information, see the WM_KILLFOCUS topic in the "Keyboard Input Reference" section, and the "Message Deadlocks" section of the "About Messages and Message Queues" topic in the MSDN library at http://msdn.microsoft.com/library.
          /// @warning For more information about handling events, see Handling and Raising Events.
          /// @warning The following code example uses the Enter event to change the foreground and background colors of a TextBox under particular conditions.
          /// @code
          /// void textBox1_Enter(const object& sender, const System::EventArgs& e) {
          ///   // If the TextBox contains text, change its foreground and background colors.
          ///   if (textBox1->Text() != String::Empty) {
          ///     textBox1->ForeColor(Color::Red());
          ///     textBox1->BackColor(Color::Black());
          ///     // Move the selection pointer to the end of the text of the control.
          ///     textBox1->Select(textBox1->Text().GetLength(), 0);
          ///   }
          /// }
          /// void textBox1_Leave(const object& sender, const System::EventArgs& e) {
          ///   // Reset the colors and selection of the TextBox after focus is lost.
          ///   textBox1->ForeColor(Color::Black());
          ///   textBox1->BackColor(Color::White());
          ///   textBox1->Select(0, 0);
          /// }
          /// @endcode
          System::EventHandler Enter;

          /// @brief Occurs when the Control.Font property value changes.
          /// @remarks This event is raised if the Font property is changed by either a programmatic modification or through interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @remarks The following code example demonstrates the FontChanged event.
          /// @code
          /// #include <Pcf/Pcf>
          ///
          /// using namespace System;
          /// using namespace System::Collections::Generic;
          /// using namespace System::ComponentModel;
          /// using namespace System::Data;
          /// using namespace System::Drawing;
          /// using namespace System::Text;
          /// using namespace System::Windows::Forms;
          ///
          /// class Form1 : Form {
          /// private:
          ///   UniquePointer<RadioButton> radioButton1;
          ///   UniquePointer<RadioButton> radioButton2;
          /// public:
          ///   static void Main() {
          ///     Application::EnableVisualStyles();
          ///     Application::SetCompatibleTextRenderingDefault(false);
          ///     Application::Run(Form1());
          ///   }
          ///
          ///   Form1() {
          ///     InitializeComponent();
          ///   }
          /// private:
          ///   void InitializeComponent(){
          ///     radioButton1 = new System::Windows::Forms::RadioButton();
          ///     radioButton2 = new System::Windows::Forms::RadioButton();
          ///     SuspendLayout();
          ///     //
          ///     // radioButton1
          ///     //
          ///     radioButton1->AutoSize(true);
          ///     radioButton1->Location(System::Drawing::Point(0, 0));
          ///     radioButton1->Name("radioButton1");
          ///     radioButton1->Size(System::Drawing::Size(62, 17));
          ///     radioButton1->SetTabIndex(0);
          ///     radioButton1->SetTabStop(true);
          ///     radioButton1->Text("Button1");
          ///     radioButton1->SetUseVisualStyleBackColor(true);
          ///     radioButton1->FontChanged += System::EventHandler(*this, &radioButton1_FontChanged);
          ///     //
          ///     // radioButton2
          ///     //
          ///     radioButton2->AutoSize(true);
          ///     radioButton2->Location(System::Drawing::Point(0, 39));
          ///     radioButton2->Name("radioButton2");
          ///     radioButton2->Size(System::Drawin::Size(126, 17));
          ///     radioButton2->SetTabIndex(1);
          ///     radioButton2->SetTabStop(true);
          ///     radioButton2->Text("Change Button1 font.");
          ///     radioButton2->SetUseVisualStyleBackColor(true);
          ///     radioButton2->CheckedChanged += System::EventHandler(*this, &radioButton2_CheckedChanged);
          ///     //
          ///     // Form1
          ///     //
          ///     SetClientSize(System::Drawing::Size(292, 273));
          ///     GetControls().Add(*radioButton2);
          ///     GetControls().Add(*radioButton1);
          ///     Name("Form1");
          ///     ResumeLayout(false);
          ///     PerformLayout();
          ///   }
          /// public:
          ///   void radioButton2_CheckedChanged(const object& sender, const EventArgs& e) {
          ///     radioButton1->setFont(System::Drawing::Font("Microsoft Sans Serif", 9F, System::Drawing::FontStyle.Bold, System::Drawing::GraphicsUnit.Point, ((byte)(0))));
          ///   }
          ///   void radioButton1_FontChanged(const object& sender, const EventArgs& e) {
          ///     MessageBox::Show("The font has been changed.");
          ///   }
          /// };
          ///
          /// pcf_startup (Form1());
          /// @endcode
          System::EventHandler FontChanged;

          /// @brief Occurs when the value of the Control::SetForeColor property changes.
          /// @remarks This event is raised if the ForeColor property is changed by either a programmatic modification or user interaction.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @remarks The following code example is an event handler that is executed when the Text property value changes. The Control class has several methods with the name pattern PropertyName Changed that are raised when the corresponding PropertyName value changes(PropertyName represents the name of the corresponding property).
          /// @remarks The following code example changes the ForeColor of a TextBox displaying currency data. The example converts the text to a decimal number and changes the ForeColor to Color.Red if the number is negative and to Color.Black if the number is positive. This example requires that you have a Form that contains a TextBox.
          /// @code
          /// void CurrencyTextBoxTextChanged(const object& sender, const EventArgs& e) {
          ///   try {
          ///     // Convert the text to a Double and determine if it is a negative number.
          ///     if (Double::Parse(currencyTextBox->Text()) < 0) {
          ///       // If the number is negative, display it in Red.
          ///       currencyTextBox->ForeColor(Color::Red());
          ///     } else {
          ///       // If the number is not negative, display it in Black.
          ///       currencyTextBox->ForeColor(Color::Black());
          ///     }
          ///   } catch {
          ///     // If there is an error, display the text using the system colors.
          ///     currencyTextBox->ForeColor(SystemColors::ControlText());
          ///   }
          /// }
          /// @endcode
          System::EventHandler ForeColorChanged;

          /// @brief Occurs during a drag operation.
          /// @remarks The GiveFeedback event is raised when a drag-and-drop operation is started. With the GiveFeedback event, the source of a drag event can modify the appearance of the mouse pointer in order to give the user visual feedback during a drag-and-drop operation.
          /// @remarks The following describes how and when events related to drag-and-drop operations are raised.
          /// @remarks The DoDragDrop method determines the control under the current cursor location. It then checks to see if the control is a valid drop target.
          /// @remarks If the control is a valid drop target, the GiveFeedback event is raised with the drag-and-drop effect specified. For a list of drag-and-drop effects, see the DragDropEffects enumeration.
          /// @remarks Changes in the mouse cursor position, keyboard state, and mouse button state are tracked.
          /// * If the user moves out of a window, the DragLeave event is raised.
          /// * If the mouse enters another control, the DragEnter for that control is raised.
          /// * If the mouse moves but stays within the same control, the DragOver event is raised.
          /// @remarks If there is a change in the keyboard or mouse button state, the QueryContinueDrag event is raised and determines whether to continue the drag, to drop the data, or to cancel the operation based on the value of the Action property of the event's QueryContinueDragEventArgs.
          /// * If the value of DragAction is Continue, the DragOver event is raised to continue the operation and the GiveFeedback event is raised with the new effect so appropriate visual feedback can be set. For a list of valid drop effects, see the DragDropEffects enumeration.
          /// @note The DragOver and GiveFeedback events are paired so that as the mouse moves across the drop target, the user is given the most up-to-date feedback on the mouse's position.
          /// * If the value of DragAction is Drop, the drop effect value is returned to the source, so the source application can perform the appropriate operation on the source data; for example, cut the data if the operation was a move.
          /// * If the value of DragAction is Cancel, the DragLeave event is raised.
          /// @note For more information about handling events, see Handling and Raising Events.
          /// @note The following code example demonstrates a drag-and-drop operation between two ListBox controls. The example calls the DoDragDrop method when the drag action starts. The drag action starts if the mouse has moved more than SystemInformation.DragSize from the mouse location during the MouseDown event. The IndexFromPoint method is used to determine the index of the item to drag during the MouseDown event.
          /// @note The example also demonstrates using custom cursors for the drag-and-drop operation. The example requires that two cursor files, 3dwarro.cur and 3dwno.cur, exist in the application directory, for the custom drag and no-drop cursors, respectively. The custom cursors will be used if the UseCustomCursorsCheck CheckBox is checked. The custom cursors are set in the GiveFeedback event handler.
          /// @note The keyboard state is evaluated in the DragOver event handler for the right ListBox, to determine what the drag operation will be based on state of the SHIFT, CTRL, ALT, or CTRL+ALT keys. The location in the ListBox where the drop would occur is also determined during the DragOver event. If the data to drop is not a String, then the DragEventArgs.Effect is set to None in DragDropEffects. Finally, the status of the drop is displayed in the DropLocationLabel Label.
          /// @note The data to drop for the right ListBox is determined in the DragDrop event handler and the String value is added at the appropriate place in the ListBox. If the drag operation moves outside the bounds of the form, then the drag-and-drop operation is canceled in the QueryContinueDrag event handler.
          /// @note This code excerpt demonstrates using the GiveFeedback event. See the DoDragDrop method for the complete code example.
          GiveFeedbackEventHandler GiveFeedback;

          /// @brief Occurs when the control receives focus.
          /// @remarks When you change the focus by using the keyboard (TAB, SHIFT+TAB, and so on), by calling the Select or SelectNextControl methods, or by setting the ContainerControl.ActiveControl property to the current form, focus events occur in the following order:
          /// * Enter
          /// * GotFocus
          /// * Leave
          /// * Validating
          /// * Validated
          /// * LostFocus
          /// @remarks When you change the focus by using the mouse or by calling the Focus method, focus events occur in the following order:
          /// * Enter
          /// * GotFocus
          /// * LostFocus
          /// * Leave
          /// * Validating
          /// * Validated

          /// @remarks If the CausesValidation property is set to false, the Validating and Validated events are suppressed.
          /// @note The GotFocus and LostFocus events are low-level focus events that are tied to the WM_KILLFOCUS and WM_SETFOCUS Windows messages. Typically, the GotFocus and LostFocus events are only used when updating UICues or when writing custom controls. Instead the Enter and Leave events should be used for all controls except the Form class, which uses the Activated and Deactivate events. For more information about the GotFocus and LostFocus events, see the WM_SETFOCUS and WM_KILLFOCUS topics in the "Keyboard Input Reference" section in the MSDN library at http://msdn.microsoft.com/library.
          /// @warning Do not attempt to set focus from within the Enter, GotFocus, Leave, LostFocus, Validating, or Validated event handlers. Doing so can cause your application or the operating system to stop responding. For more information, see the WM_KILLFOCUS topic in the "Keyboard Input Reference" section, and the "Message Deadlocks" section of the "About Messages and Message Queues" topic in the MSDN library at http://msdn.microsoft.com/library.
          /// @warning For more information about handling events, see Handling and Raising Events.
          /// @warning The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the GotFocus event. This report helps you to learn when the event occurs and can assist you in debugging.
          /// @warning To run the example code, paste it into a project that contains an instance of a type that inherits from Control, such as a Button or ComboBox. Then name the instance Control1 and ensure that the event handler is associated with the GotFocus event.
          /// @code
          /// void Control1_GotFocus(const Object& sender, const EventArgs& e) {
          ///   MessageBox::Show("You are in the Control::GotFocus event.");
          /// }
          /// @endcode
          System::EventHandler GotFocus;

          /// @brief Occurs when a handle is created for the control.
          System::EventHandler HandleCreated;

          /// @brief Occurs when the control's handle is in the process of being destroyed.
          System::EventHandler HandleDestroyed;

          /// @brief Occurs when the user requests help for a control.
          HelpEventHandler HelpRequested;

          /// @brief Occurs when the Control.ImeMode property has changed.
          System::EventHandler ImeModeChanged;

          /// @brief Occurs when a control's display requires redrawing.
          InvalidateEventHandler Invalidated;

          /// @brief Occurs when a key is pressed while the control has focus.
          KeyEventHandler KeyDown;

          /// @brief Occurs when a key is pressed while the control has focus.
          KeyPressEventHandler KeyPress;

          /// @brief Occurs when a key is released while the control has focus.
          KeyEventHandler KeyUp;

          /// @brief Occurs when a control should reposition its child controls.
          LayoutEventHandler Layout;

          /// @brief Occurs when the input focus leaves the control.
          System::EventHandler Leave;

          /// @brief Occurs when the Control.Location property value has changed.
          System::EventHandler LocationChanged;

          /// @brief Occurs when the control loses focus.
          System::EventHandler LostFocus;

          /// @brief Occurs when the control's margin changes.
          System::EventHandler MarginChanged;

          /// @brief Occurs when the control loses mouse capture.
          System::EventHandler MouseCaptureChanged;

          /// @brief Occurs when the control is clicked by the mouse.
          MouseEventHandler MouseClick;

          /// @brief Occurs when the control is double clicked by the mouse.
          MouseEventHandler MouseDoubleClick;

          /// @brief Occurs when the mouse pointer is over the control and a mouse button is pressed.
          MouseEventHandler MouseDown;

          /// @brief Occurs when the mouse pointer enters the control.
          System::EventHandler MouseEnter;

          /// @brief Occurs when the mouse pointer rests on the control.
          System::EventHandler MouseHover;

          /// @brief Occurs when the mouse pointer leaves the control.
          System::EventHandler MouseLeave;

          /// @brief Occurs when the mouse pointer is moved over the control.
          MouseEventHandler MouseMove;

          /// @brief Occurs when the mouse pointer is over the control and a mouse button is released.
          MouseEventHandler MouseUp;

          /// @brief Occurs when the mouse wheel moves while the control has focus.
          MouseEventHandler MouseWheel;

          /// @brief Occurs when the control is moved.
          System::EventHandler Move;

          /// @brief Occurs when the control's padding changes.
          System::EventHandler PaddingChanged;

          /// @brief Occurs when the control is redrawn.
          PaintEventHandler Paint;

          /// @brief Occurs when the Control.Parent property value changes.
          System::EventHandler ParentChanged;

          /// @brief Occurs before the Control::KeyDown event when a key is pressed while focus is on this control.
          System::EventHandler PreviewKeyDown;

          /// @brief Occurs when System::Windows::Forms::AccessibleObject is providing help to accessibility applications.
          System::EventHandler QueryAccessibilityHelp;

          /// @brief Occurs during a drag-and-drop operation and enables the drag source to determine whether the drag-and-drop operation should be canceled.
          System::EventHandler QueryContinueDrag;

          /// @brief Occurs when the value of the Control.Region property changes.
          System::EventHandler RegionChanged;

          /// @brief Occurs when the control is resized.
          System::EventHandler Resize;

          /// @brief Occurs when the Control.RightToLeft property value changes.
          System::EventHandler RightToLeftChanged;

          /// @brief Occurs when the Control::SetSize property value changes.
          System::EventHandler SizeChanged;

          /// @brief Occurs when the control style changes.
          System::EventHandler StyleChanged;

          /// @brief Occurs when the system colors change.
          System::EventHandler SystemColorChanged;

          /// @brief Occurs when the Control.TabIndex property value changes.
          System::EventHandler TabIndexChanged;

          /// @brief Occurs when the Control.TabStop property value changes.
          System::EventHandler TabStopChanged;

          /// @brief Occurs when the Control.Text property value changes.
          System::EventHandler TextChanged;

          /// @brief Occurs when the control is finished validating.
          System::EventHandler Validated;

          /// @brief Occurs when the control is validating.
          System::EventHandler Validating;

          /// @brief Occurs when the Control.Visible property value changes.
          System::EventHandler VisibleChanged;

        protected:
          virtual void SetAccessibleDefaultActionDescription(const string& accessibleDefaultActionDescription);
          
          virtual void SetAccessibleDescription(const string& accessibleDescription);
          
          virtual void SetAccessibleName(const string& accessibleName);
          
          virtual void SetAllowDrop(bool allowDrop);
          
          virtual void SetAnchor(AnchorStyles anchor);
          
          virtual void SetAutoScrollOffset(const System::Drawing::Point& autoScrollOffset);
          
          virtual void SetAutoSize(bool autoSize);
          
          virtual void SetBackColor(const System::Drawing::Color& color);
          
          virtual const Drawing::Image& GetBackgroundImage() const;
          
          virtual void SetBackgroundImage(const Drawing::Image& backgroundImage);
          
          virtual ImageLayout GetBackgroundImageLayout() const;
          
          virtual void SetBackgroundImageLayout(ImageLayout backgroundImageLayout);
          
          virtual bool GetCanEnableIme() const;
          
          virtual bool GetCanFocus() const {return false;}
          
          virtual bool GetCanSelect() const {return false;}
          
          virtual bool GetCausesValidation() const;
          
          virtual void SetCausesValidation(bool causesValidation);
          
          virtual void SetClientSize(const System::Drawing::Size& clientSize);
          
          virtual const System::Windows::FormsD::Cursor& GetCursor() const;
          
          virtual void SetCursor(const System::Windows::FormsD::Cursor& cursor);
          
          virtual Drawing::Size GetDecorationSize() const;
          
          virtual const System::Windows::FormsD::Cursor& GetDefaultCursor() const;
          
          virtual System::Drawing::Size GetDefaultSize() const {return System::Drawing::Size(0, 0);}
          
          virtual DockStyle GetDock() const;
          
          virtual void SetDock(DockStyle dock);
          
          virtual bool GetEnabled() const;
          
          virtual void SetEnabled(bool enabled);
          
          virtual bool GetFocused() const;
          
          virtual const System::Drawing::Font& GetFont() const;
          
          virtual void SetFont(const System::Drawing::Font& font);
          
          virtual void SetForeColor(const System::Drawing::Color& color);
          
          virtual const IWidget& GetHandle() const;
          
          virtual void SetLocation(const System::Drawing::Point& location);
          
          virtual const string& GetName() const;
          
          virtual void SetName(const string& name);
          
          virtual const Control& GetParent() const;
          
          virtual void SetParent(const Control& parent);
          
          virtual void SetSize(Drawing::Size size);
          
          virtual string GetText() const;
          
          virtual void SetText(const string& text);
          
          virtual bool GetVisible() const;
          
          virtual void SetVisible(bool visible);
          
          /// @brief Raises the AutoSizeChanged event.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          /// @remarks The OnAutoSizeChanged method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
          virtual void OnAutoSizeChanged(const EventArgs& e) {
            if (this->autoSize)
              this->Size = this->GetComputeSize().ToSize();
            
            this->AutoSizeChanged(*this, e);
          }
          
          virtual void OnBackColorChanged(const EventArgs& e) {this->BackColorChanged(*this, e);}
          
          virtual void OnClientSizeChanged(const EventArgs& e) {
            if (this->parent)
              this->parentSize = this->parent->Size();
            
            this->ClientSizeChanged(*this, e);
          }

          virtual void OnClick(const EventArgs& e) {this->Click(*this, e);}
          
          virtual void OnDoubleClick(const EventArgs& e) {this->DoubleClick(*this, e);}
          
          virtual void OnDragDrop(DragEventArgs& e) {this->DragDrop(*this, e);}
          
          virtual void OnDragEnter(DragEventArgs& e) {this->DragEnter(*this, e);}
          
          virtual void OnDragLeave(DragEventArgs& e) {this->DragLeave(*this, e);}
          
          virtual void OnDragOver(DragEventArgs& e) {this->DragOver(*this, e);}
          
          virtual void OnEnter(const EventArgs& e) {this->Enter(*this, e);}
          
          virtual void OnForeColorChanged(const EventArgs& e) {this->ForeColorChanged(*this, e);}
          
          virtual void OnKeyDown(KeyEventArgs& e) {this->KeyDown(*this, e);}
          
          virtual void OnKeyPress(KeyPressEventArgs& e) {this->KeyPress(*this, e);}
          
          virtual void OnKeyUp(KeyEventArgs& e) {this->KeyUp(*this, e);}
          
          virtual void OnLeave(const EventArgs& e) {this->Leave(*this, e);}
          
          virtual void OnLocationChanged(const EventArgs& e) {
            this->graphics.Offset(this->GetOffsetFromForm());
            this->LocationChanged(*this, e);
          }
          
          virtual void OnLayout(const LayoutEventArgs& e) {this->Layout(*this, e);}
          
          virtual void OnMouseClick(const MouseEventArgs& e) {this->MouseClick(*this, e);}
          
          virtual void OnMouseDoubleClick(const MouseEventArgs& e) {this->MouseDoubleClick(*this, e);}
          
          virtual void OnMouseDown(const MouseEventArgs& e) {this->MouseDown(*this, e);}
          
          virtual void OnMouseEnter(const EventArgs& e) {this->MouseEnter(*this, e);}
          
          virtual void OnMouseHover(const EventArgs& e) {this->MouseHover(*this, e);}
          
          virtual void OnMouseLeave(const EventArgs& e) {this->MouseLeave(*this, e);}
          
          virtual void OnMouseMove(const MouseEventArgs& e) {this->MouseMove(*this, e);}
          
          virtual void OnMouseUp(const MouseEventArgs& e) {this->MouseUp(*this, e);}
          
          virtual void OnMouseWheel(const MouseEventArgs& e) {this->MouseWheel(*this, e);}
          
          virtual void OnPaint(PaintEventArgs& e) {
            this->widget->Draw();
            this->Paint(*this, e);
          }

          virtual void OnParentChanged(const EventArgs& e) {
            if (this->parent != null) {
              parentLocation = this->parent->Location();
              parentSize = this->parent->Size();
            }
            
            this->ParentChanged(*this, e);
          }
          
          virtual void OnSizeChanged(const EventArgs& e) {
            this->SizeChanged(*this, e);
          }
          
          virtual void OnTextChanged(const EventArgs& e) {
            if (this->autoSize)
              this->Size = this->GetComputeSize().ToSize();
            this->TextChanged(*this, e);
          }
          
          System::Drawing::Point PointToForm(const System::Drawing::Point point) const;
          
          System::Drawing::Point GetOffsetFromForm() const {
            return PointToForm(System::Drawing::Point(0, 0));
          }
          
          virtual System::Drawing::SizeF GetComputeSize() const;

          void Register(UniquePointer<IWidget> widget);
          void Unregister() {this->widget.Reset();}
          /// @cond
          SharedPointer<IWidget> widget;
          string accessibleDefaultActionDescription;
          string accessibleDescription;
          string accessibleName;
          bool allowDrop = false;
          System::Windows::FormsD::AnchorStyles anchor = System::Windows::FormsD::AnchorStyles(int(System::Windows::FormsD::AnchorStyles::Left) | int(System::Windows::FormsD::AnchorStyles::Top));
          System::Drawing::Point autoScrollOffset;
          bool autoSize = false;
          System::Drawing::Color backColor;
          System::Drawing::Image backgroundImage = System::Drawing::Image::None;
          ImageLayout backgroundImageLayout;
          bool causesValidation = false;
          Drawing::Size clientSize;
          ControlCollection controls {*this};
          string companyName = "Pcf, GAMMA Soft";
          bool containsFocus = false;
          System::Windows::FormsD::Cursor cursor;
          System::Windows::FormsD::Cursor defaultCursor;
          DockStyle dock = DockStyle::None;
          static const object* dragDropData;
          static DragDropEffects dragDropAllowedEffects;
          static DragDropEffects dragDropEffects;
          bool enabled = true;
          System::Drawing::Font font;
          System::Drawing::Color foreColor;
          System::Drawing::Graphics graphics;
          mutable System::Drawing::Point location;
          string name;
          Control* oldParent = null;
          Control* parent = null;
          Drawing::Point parentLocation;
          Drawing::Size parentSize;
          Drawing::Size previousClientSize;
          MethodInvoker invoker;
          Drawing::Size size;
          int32 suspendLayout {0};
          string text;
          bool useWaitCursor = false;
          bool visible = true;
          /// @endcond
          
        private:
          friend class Application;
          
          bool hover = false;
          void __OnNoEvent__();
          void __OnEnter__();
          void __OnMove__();
          void __OnPush__();
          void __OnRelease__();
          void __OnMouseWheel__();
          void __OnLeave__();
          void __OnDrag__();
          bool __OnFocus__();
          void __OnUnfocus__();
          void __OnKeyDown__();
          void __OnKeyUp__();
          void __OnClose__();
          void __OnShortcut__();
          void __OnDeactivate__();
          void __OnActivate__();
          void __OnHide__();
          void __OnShow__();
          void __OnPaste__();
          void __OnSelectionClear__();
          bool __OnDndEnter__();
          bool __OnDndDrag__();
          bool __OnDndRelease__();
          bool __OnDndLeave__();
          void __OnScreenConfiguartionChange__();
          void __OnFullscreen__();
          void __OnFormSizeChange__();
          void __OnFormMove__();
          
          virtual bool HasClickRaised(MouseButtons button) const {
            switch (button) {
              case MouseButtons::Left: return true;
              case MouseButtons::Right: return true;
              case MouseButtons::Middle: return true;
              case MouseButtons::XButton1: return true;
              case MouseButtons::XButton2: return true;
              default: return true;
            }
          }
          
          virtual bool HasClickReplaceDoubleClick(MouseButtons button) const {
            switch (button) {
              case MouseButtons::Left: return false;
              case MouseButtons::Right: return false;
              case MouseButtons::Middle: return false;
              case MouseButtons::XButton1: return false;
              case MouseButtons::XButton2: return false;
              default: return false;
            }
          }
          
          virtual bool HasDoubleClickRaised(MouseButtons button) const {
            switch (button) {
              case MouseButtons::Left: return true;
              case MouseButtons::Right: return true;
              case MouseButtons::Middle: return true;
              case MouseButtons::XButton1: return true;
              case MouseButtons::XButton2: return true;
              default: return true;
            }
          }
          
          static void InvokeMethod(void* control) {((Control*)control)->invoker();}
          
          void PerformLayoutIfNotSuspend() {
            Control* control = this;
            do {
              if (control->suspendLayout != 0)
                return;
              control = control->parent;
            } while (control != null);
            
            this->PerformLayout();
            this->OnLayout(LayoutEventArgs());
          }
        };
      }
    }
  }
}
