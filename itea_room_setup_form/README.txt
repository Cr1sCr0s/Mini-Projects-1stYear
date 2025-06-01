ITEA Room Setup Form — HTML Project
====================================

This project implements an HTML form for customers to place a furniture order from ITEA, a fictional furniture company. The form is designed to collect customer information, room details, and delivery preferences with full form validation and accessibility in mind.

---

📋 Form Sections
----------------

The form is organized into three sections using the `<fieldset>` element:

1. **Customer Information**
   - Full Name (`name`)
   - Mobile Number (`mobile`)
     - Placeholder: `09XXXXXXXXX`
     - Must start with "09" and be 11 digits long
   - Email Address (`email`)
     - Must follow valid email format

2. **Room Details**
   - Number of Occupants (`occupants`)
   - Room Type (`room_type`) — *Dropdown*
     - Options: Bedroom (default), Living Room, Office, Children's Room
   - Bed Size (`bed_size`) — *Dropdown*
     - Options: Single (default), Double, Queen, King
   - Cabinets (`cabinets`) — *Dropdown*
     - Options: Bookcases (default), Storage Shelves, Wall Shelves
   - Tables (`tables`) — *Checkboxes*
     - Options: Desk, Bedside Table, Multifunctional Table, Dressing Table
   - Decorative Additions (`decor`) — *Checkboxes*
     - Options: Mirror, Rug, Wall Accents, Clock
   - Room Size (`room_size`) — *Radio buttons*
     - Options: Small, Medium, Large, Extra Large

3. **Delivery Details**
   - Delivery Address (`delivery_address`)
     - Placeholder: `Address here…`
   - Delivery Date (`delivery_date`)
   - Delivery Time (`delivery_time`)

---

✅ Validation Rules
-------------------

- **Required Fields:**
  - Name
  - Mobile Number (with 09 prefix and exactly 11 digits)
  - Email Address (valid email format)
  - Delivery Address
  - Delivery Date
  - Delivery Time

- **Default Values:**
  - Room Type: *Bedroom*
  - Bed Size: *Single*
  - Cabinets: *Bookcases*

---

🎯 Functional Buttons
---------------------

- **Submit Button:**
  - Triggers all validation rules before submission.

- **Reset Button:**
  - Clears all fields in the form.

---

🧱 Accessibility & HTML Structure
---------------------------------

- All input fields include both `id` and `name` attributes.
- Every form element is associated with a `<label>` for clarity and accessibility.
- Radio buttons and checkboxes are linked to their corresponding labels using `for` and `id` attributes.

---

📁 File Structure
------------------
index.html # Contains the complete form
style.css # (Optional) Custom styles if used
script.js # (Optional) Client-side validation or interactivity