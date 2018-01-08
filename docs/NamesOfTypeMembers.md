[![Switch Header](Pictures/SwitchNativeC++port.png)](https://gammasoft71.wixsite.com/switch)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|---------------------------------------------------------|

Types are made of members: methods, properties, events, constructors, and fields. The following sections describe guidelines for naming type members.

# Names of Methods

Because methods are the means of taking action, the design guidelines require that method names be verbs or verb phrases. Following this guideline also serves to distinguish method names from property and type names, which are noun or adjective phrases.

**√ DO** give methods names that are verbs or verb phrases. 
​text enums, etc.).

```c++
​class String : public object {
​public:
  int CompareTo(...);
  Array<string> Split(...);
  string Trim();
};
```

# Names of Properties

Unlike other members, properties should be given noun phrase or adjective names. That is because a property refers to data, and the name of the property reflects that. PascalCasing is always used for property names.

**√ DO** name properties using a noun, noun phrase, or adjective.

**X DO NOT** have properties that match the name of "Get" or "Set" methods as in the following example: 

```c++
property_<string> TextWriter {
  get_ { ... },
  set_ { ... }
};
string GetTextWriter(int32 value) { ... }
```

This pattern typically indicates that the property should really be a method.

**√ DO** name collection properties with a plural phrase describing the items in the collection instead of using a singular phrase followed by "List" or "Collection."

**√ DO** name Boolean properties with an affirmative phrase (CanSeek instead of CantSeek). Optionally, you can also prefix Boolean properties with "Is," "Can," or "Has," but only where it adds value.

**√ CONSIDER** giving a property the same name as its type.
For example, the following property correctly gets and sets an enum value named Color, so the property is named Color:

```c++
namespace Windows {
  enum class Color {
    ...
  };
​
  class Control : public object {
  public:
    property_<Forms::Color> Color {
      get_ { ... },
      set_ { ... }
    };
  };
}
```

# Names of Events

Events always refer to some action, either one that is happening or one that has occurred. Therefore, as with methods, events are named with verbs, and verb tense is used to indicate the time when the event is raised.

**√ DO** name events with a verb or a verb phrase.

Examples include Clicked, Painting, DroppedDown, and so on.

**√ DO** give events names with a concept of before and after, using the present and past tenses.

For example, a close event that is raised before a window is closed would be called Closing, and one that is raised after the window is closed would be called Closed.

**X DO NOT** use "Before" or "After" prefixes or postfixes to indicate pre- and post-events. Use present and past tenses as just described.

**√ DO** name event handlers (delegates used as types of events) with the "EventHandler" suffix, as shown in the following example:

```c++
using ClickedEventHandler = Delegate<const object&, const EventArgs&>;
```
**√ DO** use two parameters named sender and e in event handlers.

The sender parameter represents the object that raised the event. The sender parameter is typically of type object, even if it is possible to employ a more specific type.

**√ DO** name event argument classes with the "EventArgs" suffix.

# Names of Fields

The field-naming guidelines apply to static public and protected fields. Internal and private fields are not covered by guidelines, and public or protected instance fields are not allowed by the Member Design Guidelines.

**√ DO** use PascalCasing in field names.

**√ DO** name fields using a noun, noun phrase, or adjective.

**X DO NOT** use a prefix for field names.

For example, do not use "g_" or "s_" to indicate static fields.

# See also
​
Other Resources

* [Framework Design Guidelines](FrameworkDesignGuidelines.md)
* [Naming Guidelines](NamingGuidelines.md)

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
