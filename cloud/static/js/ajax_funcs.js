/**
 * Created by nathanmoreno on 1/20/17.
 */

function submit_form(form) {
    $(form).ajaxSubmit({
        beforeSubmit: function() {  },
        success: function(response) { console.log(response); },
        error: function(request, errordata, errorObject) { alert(errorObject.toString()); }
        //dataType: 'json'
    });
}

onload

